//
// Created by JIYOUNG.P on 2022-03-07.
//

#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * ver1. set을 이요한 풀이입니다.
 * 정렬을 할 필요가 없이, 삽입과 검색만 일어나는 문제입니다.
 * 입력의 수가 최대 1,000,000으로 삽입과 탐색이 많이 일어납니다.
 * 따라서, O(log N)의 set이 아니라 O(1)인 unordered_set을 사용해서 풀어야 합니다.
 * */

int main() {
    // 입출력 처리 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int t; //테스트케이스 개수
    cin >> t; //테스트케이스 개수 입력
    while (t--) { //케이스 개수별 계산 while문
        int n, m, input; //정수 개수, 입력 위한 값
        unordered_set<int> note1; //수첩1 set

        // 수첩1에 해당되는 원소들을 unordered_set에 삽입
        cin >> n; //수첩1 정수 개수 입력
        while (n--) { //수첩1 각 원소 입력 while문
            cin >> input; //input에 원소 입력
            note1.insert(input); //input값 set에 삽입
        }
        cin >> m; //수첩2 정수 개수 입력
        while (m--) { //수첩2 각 원소 입력&판별 while문
            cin >> input; //input(수첩2 원소) 입력
            // 반복자를 이용해서 원소가 셋에 포함되어 있는지 확인
            auto iter = note1.find(input); //find 활용 반복자 설정
            if (iter == note1.end()) { //end 활용, 없을 경우
                cout << "0\n";
            }
            else { //있을 경우
                cout << "1\n";
            }
        }
    }
    return 0;
}