#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//함수 S의 계산
int calcS(int n, vector<int> a, vector<int> b) { //S값(최솟값) 계산 함수
    int s = 0; //최솟값 초기화
    for (int i = 0; i < n; i++) { //함수 S 계산 위한 for문
        s += (a[i] * b[i]); //S값 계산
    }
    return s;
}

/**
 * 문제에서 B를 재배열하지 말라곤 했지만, 해야하는 문제
 * 각 배열에서 가장 큰 값과 가장 작은 값을 곱해야 최솟값이 나옴!
 */

int main() {
    int n; //배열 길이
    vector<int> a, b; //배열 A, B

    //입력
    cin >> n; //배열 길이 받기
    a.assign(n, 0); //배열 길이 설정, 초기화
    b.assign(n, 0); //배열 길이 설정, 초기화
    for (int i = 0; i < n; i++) { //배열A 입력 위한 for문
        cin >> a[i]; //배열A 원소 입력
    }
    for (int i = 0; i < n; i++) { //배열B 입력 위한 for문
        cin >> b[i]; //배열B 원소 입력
    }

    //연산
    sort(a.begin(), a.end()); //오름차순 정렬
    sort(b.begin(), b.end(), greater<>()); //내림차순 정렬
    int result = calcS(n, a, b); //최솟값 계산해 result에 저장

    //출력
    cout << result; //최솟값 출력
    return 0;
}