3. nested def 알고리즘
    - 밑의 3-step config analysis로 해결 
        -> 참고: 현재 디자인은 일단 UD만 fuzzing input mutation으로 고려. 결과에 따라 바뀔수있음
    - 세부 디자인
        S1. config 할때 ifdef하나 데이터 얻을떄 내부에서 정의되는 nested define (ND라고 합시다)들도 다 찾아오고 값도 가져오기 
            - nested define이 아니고 일반적인 경우는 UD (unnested define) 
            - ND를 모두 모아서 global set에 저장 ("NDset"이라 가정)
            - full condition 먼저 업데이트 (= FC -> e.g., A == 1 && B == 1)
            - ifdef 조건이 ND와 UD 경우를 구별할 데이터 필드 만들기 
                - 이건 기존에 추가 데이터 필요
                    - a. ND가 ifdef 블록 안에 존재여부 
                        - default "False"
                    - b. 어느 ND가 해당 ifdef 조건 만족에 영향 미치는지 (map으로 만들어야할듯) (if "S1.a" is true)
                    - c. 어느 UD가 해당 ifdef 조건 만족에 영향 미치는지                 (if "S1.a" is true)
                    - d. 어느 ND가 ifdef 블록 안에 정의 되어있는지 (map으로 만들어야될듯)
            - S1.d 업데이트 (e.g., ifdef 블록 안에 정의된 define) 
            - S1.c 업데이트 (추후 분석때 ND면 옮겨야함) 
        S2. 그럼 define dependency를 반복적 (iteratively) tracking해야함
            - 모든 ifdef를 검색하며 "NDset"에 포함된 ND가 ifdef 조건인 경우 
                - 해당 ifdef는 ND에 따라 만족되니 "S1.a" 를 true로 업뎃해야함 
            - ND와 연관된 ifdef 조건을 만족하기위해 어떤 UD (=ND를 포함하는 ifdef의 UD) 바꾸어야하는지 찾아야함.
                - 그를 만족하기위한 조건 찾고 map에 그 조건들 모두 재귀적으로 찾으며 업데이트
                    - "S1.c"에서 ND인것들 "S1.b"로 옮기기 (밑 예제에서 3.2->3.3에서 바뀐 부분 참고)
                    - ND가 조건에 맞추어 만족되기위한 조건들을 반복적으로 backward로 찾아서 업데이트해감 
                        -> 내부적으로 SMT 돌리면서 S2는 반복적으로 돌아야함 (밑의 예시에서 3.2->3.5)
        S3. ifdef의 조건을 만족하기위한 UD들을 SMT로 생성하기 
            - 이제 "S1.a"가 true인 경우에 대해서 추가 업뎃필요
                - "S1.b"와 "S1.c"를 모두 업데이트  
                - 참고: 이중 "S1.b"는 직접적인 퍼징 대상은 아님 
                    - 왜냐하면 ifdef의 내부에 정의되는 "ND들은 fuzzing mutation으로 바꾸면 안됨"
                        -> 이건 ifdef가 만족할경우에만 바뀌니 
                        -> 즉 퍼징 대상은 (아마도. 확정은 아님) UD 경우로 한정 -> 추후에 바뀔수있음 
            - SMT 조건 생성 
                - "S1.a" == False 
                    -> "S1.c" 로 퍼징
                - "S1.a" == True
                    -> "S1.b"랑 "S1.c" -> 일반 퍼징 
            - 참고 FC가 따로 필요한 이유: 각각 condition들이 어떻게 관련있는지 알기위함 (e.g., C2 == 1 && C3 == 1의 "&&" 부분)
            
3.1 예제 
    #ifdef C1 == 1 
        #define C2 1 
        Block 1
    #endif 
    #ifdef C2 == 1 && C3 == 1
        #define C4 1
        Block 2
    #endif 
    #ifdef C4 == 1
        Block 3
    #endif 
3.2 Config 결과 예제 (S1)
    Config 1
        - FC: C1 == 1
        - S1.a: False 
        - S1.c: ["C1 == 1"]
        - S1.d: ["C2 = 1"]
    Config 2
        - FC: C2 == 1 && C3 == 1
        - S1.a: False 
        - S1.c: ["C2 == 1", "C3 == 1"]
        - S1.d: ["C4 = 1"]
    Config 3
        - FC: C4 == 1
        - S1.a: False 
        - S1.c: [C4 == 1]
3.3 Config 결과 예제 (S2)
    Config 1
        - FC: C1 == 1
        - S1.a: False 
        - S1.c: ["C1 == 1"]
        - S1.d: ["C2 = 1"]
    Config 2
        - FC: C2 == 1 && C3 == 1
        - S1.a: True                                    <- 바뀜
        - S1.b: map["C2 == 1"] =["C2 == 1"]             <- 바뀜
        - S1.c: ["C3 == 1"]                               <- 바뀜
        - S1.d: ["C4 = 1"]
    Config 3
        - FC: C4 == 1
        - S1.a: True                                    <- 바뀜
        - S1.b: map["C4 == 1"] =[C4 == 1]             <- 바뀜
        - S1.c: []                                      <- 바뀜
3.4 Config 결과 예제 (S2)
    Config 1
        - FC: C1 == 1
        - S1.a: False 
        - S1.c: ["C1 == 1"]
        - S1.d: ["C2 = 1"]
    Config 2
        - FC: C2 == 1 && C3 == 1
        - S1.a: True                    
        - S1.b: map["C2 == 1"] = ["C1 == 1"]            <- 바뀜 (C2 = 1되려면 C1 = 1가 필요)
        - S1.c: ["C3 == 1"]               
        - S1.d: ["C4 = 1"]
    Config 3
        - FC: C4 == 1
        - S1.a: True                    
        - S1.b: map["C4 == 1"] = ["C2 == 1 && C3 == 1"]         <- 바뀜 (C4 = 1되려면 C2 = 1가 필요 그리고 ND가 아닌 C3 =1도 필요)
        - S1.c: []                      
3.5 Config 결과 예제 (S2)
    Config 1
        - FC: C1 == 1
        - S1.a: False 
        - S1.c: ["C1 == 1"]
        - S1.d: ["C2 = 1"]
    Config 2
        - FC: C2 == 1 && C3 == 1
        - S1.a: True                    
        - S1.b: map["C2 == 1"] = ["C1 == 1"]            
        - S1.c: ["C3 == 1"]               
        - S1.d: ["C4 = 1"]
    Config 3
        - FC: C4 == 1
        - S1.a: True                    
        - S1.b: map["C4 == 1"] = ["C1 == 1 && C3 == 1"]         <- 바뀜 (C2 == 1 && C3 == 1되려면 C1 = 1가 필요)
        - S1.d: []      
3.6 Config 결과 예제 (S3)
    Config 1
        - FC: C1 == 1 d이니까 
        -> C1 == 1과 C1 != 1과 
    Config 2
        - FC: C2 == 1 && C3 == 1
        -> C1 == 1 && C3 == 1과 not (C1 == 1 && C3 == 1) 
    Config 3
        - FC: C4 == 1
        -> C1 == 1 && C3 == 1과 not (C1 == 1 && C3 == 1) 