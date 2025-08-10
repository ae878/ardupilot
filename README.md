
# Configuration Fuzzer - Conffuzz

### Usage - Docker
```
docker build --build-arg SCRIPT_TO_RUN=ardupilot -t fuzz_ardupilot .
docker run -d --name fuzz_ardupilot_normal ardupilot_fuzz
```


### Usage - Add new adapter
1. Use preprocessor/macro-parser for parsing macros
2. Make a custom script - use `run.py`

### 
1. run analyze_conditions.py --source-dir /~/ardupilot 

### TODOs
[x] Use callgraph to find related macros
[x] Add more adapters
ㄴ [x] rusefi
ㄴ [x] FMT-firmware
ㄴ [x] librepilot
ㄴ [?] ardupilot
ㄴ [x] wideband-controller (rusefi)
[x] heuristic rules - Check codesize when fuzzing
[x] (low priority) ir parser optimization
[x] Builder (Compile) optimization


1. build success rate
2. code size (of the binary)
3. maximum stack size (of each thread function)



python3 run_improved.py --skip-initial --timeout 3600 -r -s --threads 5 > /conffuzz/long_run.log
