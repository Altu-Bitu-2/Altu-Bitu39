#include <iostream>

using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) { //b가 0일 경우
        return a; //0으로는 나누기가 불가능, a 리턴
    }
    return gcdRecursion(b, a % b); //재귀 활용해 최대공약수 구하기
}

int main() {
    string s;

    //입력
    cin >> s; //비 입력

    //연산(입력으로부터 n, m 추출하기)
    int index = s.find(':'); //':' 위치 찾기
    int n = stoi(s.substr(0, index)); //: 이전의 문자를 숫자로 변경해 n값으로 설정
    int m = stoi(s.substr(index + 1, s.length())); //: 이후 문자를 숫자로 변경해 m값으로 설정

    //최대공약수 구하기
    int g = gcdRecursion(max(n, m), min(n, m));

    //출력
    cout << n / g << ':' << m / g << '\n';

    return 0;
}