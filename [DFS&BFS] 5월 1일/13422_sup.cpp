#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int>& house) {
    //윈도우 초기화
    int money = 0; //돈 초기화
    for (int i = 0; i < m; i++) { //연속으로 훔쳤을 때 돈 계산
        money += house[i];
    }
    int ans = money < k; //훔쳐야 하는 집 초기화 //돈이 조건보다 적다면 자동 카운트 1

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans;
    }
    for (int i = m; i < n + m - 1; i++) {
        money -= house[i - m]; //다음 윈도우에서 제외되는 돈
        money += house[i % n]; //다음 윈도우에서 추가되는 돈
        if (money < k) { //돈과 조건 비교해 자동 카운트
            ans++;
        }
    }
    return ans; //결과 출력
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {
    int t, n, m, k; //케이스 개수, 집의 개수, 훔칠 연속 집의 개수, 방범 장치 작동 조건

    cin >> t; //케이스 개수 입력
    while (t--) { //케이스 전부 끝날 때까지
        //입력
        cin >> n >> m >> k; //입력
        vector<int> house(n, 0); //각 집의 돈 벡터
        for (int i = 0; i < n; i++) { //돈 입력
            cin >> house[i];
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n'; //방법 수 계산해 출력
    }
    return 0;
}