#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> simulation(int k, queue<int>& q) {
    vector<int> result; //요세푸스 순열 반환 위한 결과 저장
    int cnt = 0; //카운트 변수

    while (!q.empty()) {
        int x = q.front();
        q.pop(); //가장 앞 정수를 빼고
        cnt++; //뺀 횟수를 카운트
        if (cnt == k) { //k번째 pop하는 원소라면
            result.push_back(x); //반환 위해 저장
            cnt = 0; //k 카운트 초기화
            continue;
        }
        q.push(x); //pop한 원소 다시 push
    }
    return result;
}

/**
 * 1. 큐에 1 ~ N까지 값 초기화
 * 2. 이후 k 번째 사람 찾기 위해 pop, push 반복
 * 3. k번째 pop 일 경우 요세푸스 순열에 저장, 이후 원소 제거 (다시 push 하지 않음!)
 */

int main() {
    int n, k;
    queue<int> q;

    //입력
    cin >> n >> k; //n, k 입력
    for (int i = 1; i <= n; i++) { //큐 초기화
        q.push(i);
    }
    //연산
    vector<int> result = simulation(k, q); //요세푸스 계산
    //출력
    cout << '<'; //출력 형식 맞추기
    for (int i = 0; i < result.size() - 1; i++) { //요세푸스 출력
        cout << result[i] << ", ";
    }
    cout << result[result.size() - 1] << '>'; //출력 형식 맞추기
    return 0;
}