#include <iostream>

using namespace std;

string solution(int x, int n) {
    if (n > 1 && n % 2 == 1) { //길이가 양수인 홀수라면
        return "ERROR"; //-x가 되므로 컴파일 실패
    }
    if (n == 1 && x < 0) { //길이가 1, 초기값이 0보다 작다면
        return "INFINITE"; //항상 while 조건이 참이므로 무한
    }
    if (n == 1 || x <= 0) { //길이가 1(위의 경우 제외 or 초기값이 0보다 작거나 같다면
        return "0"; //while 조건 만족 못하므로 0
    }
    if (n == 0) { //길이가 0인 경우(위의 경우 제외하므로 초기값은 양수)
        return "INFINITE"; //항상 while 조건 만족하므로 무한
    }
    return to_string((x - 1) / (n / 2)); //위의 경우를 제외 시 연산
}

/**
 * [화살표 연산자]
 *
 * 1. n이 1보다 큰 홀수인 경우 -> ERROR
 * 2. n이 1인데 x가 음수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 3. n이 1인데 x가 양수인 경우 or x가 0보다 작거나 같은 경우 -> while문에 진입 못함 -> 0
 * 4. n이 0인데 x가 양수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 5. 나머지 경우엔 (x - 1)을 (n / 2)로 나눈 몫을 출력
 *    - 연산했을 때 1 이상이 남을 때까지만 출력을 할 수 있으므로 1을 뺀 값에서 몫을 구함
 */

int main() {
    int x, n; //변수 초기값, 화살표 길이

    //입력
    cin >> x >> n; //초기값, 길이 입력

    //연산 & 출력
    cout << solution(x, n); //계산해 출력
    return 0;
}