import csv
import json

def csv_to_json(csv_file_path, json_file_path):
    # CSV 파일 읽기
    with open(csv_file_path, mode='r', encoding='utf-8') as csv_file:
        csv_reader = csv.DictReader(csv_file)  # 첫 번째 행을 key로 사용
        rows = list(csv_reader)  # 모든 행을 리스트로 변환
    
    # JSON 파일로 쓰기
    with open(json_file_path, mode='w', encoding='utf-8') as json_file:
        json.dump(rows, json_file, indent=4, ensure_ascii=False)

# 사용 예제
csv_file_path = 'functions.csv'  # 변환할 CSV 파일 경로
json_file_path = 'thread_functions.json'  # 저장할 JSON 파일 경로
csv_to_json(csv_file_path, json_file_path)
