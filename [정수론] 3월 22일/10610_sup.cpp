#include <iostream>
#include <algorithm>

using namespace std;

string findNumber(string s) {
    bool isTen = false; //0이 존재하는지 확인
    int sum = 0; //3의 배수인지 확인하기 위해 수 더함

    //돌면서 3의 배수와 10의 배수인지 확인
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - '0'); //각 자리의 수 더하기
        if (s[i] == '0') { //0이 들어있다면
            isTen = true; //10의 배수가 됨
        }
    }

    if (sum % 3 != 0 || !isTen) { //3의 배수가 아니거나, 10의 배수가 아니라면
        return "-1"; //-1 반환
    }

    //가장 큰 수 만들기 위해 내림차순 정렬
    sort(s.begin(), s.end(), greater<>()); //역순으로 정렬
    return s; //정렬한 스트링 반환
}

/**
 * [30]
 * 30의 배수 = 10의 배수 && 3의 배수
 * 1. 10의 배수 -> 입력된 수에 0이 포함되어 있는지 확인
 * 2. 3의 배수 -> 모든 자리수의 합이 3의 배수인지 확인
 *
 * 30의 배수임이 확인 되었으면,
 * 가장 큰 수를 만들기 위해 9부터 0까지 역순으로 나열한다.
 */

int main() {
    string s;

    //입력
    cin >> s; //수 입력

    //연산 & 출력
    cout << findNumber(s); //가능 or 불가능 판단해 계산&출력
    return 0;
}