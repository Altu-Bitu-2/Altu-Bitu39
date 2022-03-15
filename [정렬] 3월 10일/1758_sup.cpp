#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calTip(int n, vector<int>& tips) { //팁 계산 함수
    long long ans = 0; //반환할 팁
    for (int i = 0; i < n; i++) { //손님의 팁 계산+합계 패널티 for문
        int cur_tip = tips[i] - i; //순서 패널티
        if (cur_tip < 0) //음수면 팁에 더하지 않는데 처음에 내림차순 정렬했으므로 아예 break
            break;
        ans += cur_tip; //팁 합계
    }
    return ans; //팁 반환
}

/**
 * 강호가 받을 수 있는 팁이 최댓값이 되려면 팁이 많은 사람의 순위가 높아야함
 * !주의! 주어지는 N의 최대 크기가 100,000이고 팁의 최대 크기가 100,000이므로
 *       정답의 최댓값은 10^5 * (10^5+1) / 2로 int 범위를 넘기 때문에 long long 을 써야 함
 */

int main() { //메인 함수
    int n; //손님 수

    //입력
    cin >> n; //손님 수
    vector<int> tips(n, 0); //손님별 팁을 입력받을 vector
    for (int i = 0; i < n; i++) { //팁을 입력받을 for문
        cin >> tips[i]; //팁 입력
    }
    //연산
    sort(tips.begin(), tips.end(), greater<>()); //내림차순 정렬
    //출력
    cout << calTip(n, tips) << '\n'; //함수로 계산한 팁 합계 출력
    return 0;
}