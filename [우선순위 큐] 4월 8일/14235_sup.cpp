#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input;
    priority_queue<int> pq; //최대 힙

    //입력
    cin >> n; //아이들&거점지 방문 횟수
    while (n--) {
        cin >> a; //선물 개수(0인 경우 아이들)
        if (!a) { //아이들을 만난 경우
            if (pq.empty()) { //선물 x
                cout << "-1\n";
            }
            else { //선물 주기
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else { //선물을 충전하는 경우
            while (a--) {
                cin >> input;
                pq.push(input);
            }
        }
    }
    return 0;
}