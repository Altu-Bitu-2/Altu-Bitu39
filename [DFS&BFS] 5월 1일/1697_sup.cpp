#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;

int bfs(int n, int k) {
    vector<int> check(SIZE + 1, 0); //체크한 좌표인지 확인하기 위한 벡터
    queue<int> q; //큐에 좌표값 저장
    int ans = 0; //출력할 값 초기화

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n); //큐에 시작 좌표값 저장
    while (!q.empty()) { //큐에 값이 없어질 때까지
        int x = q.front(); //큐의 맨 앞 좌표 x로 초기화한 후
        q.pop(); //큐에서 삭제

        if (x == k) { //해당 좌표가 동생의 위치라면
            ans = check[x] - 1; //출력할 좌표 저장 후
            break; //계산 끝내기
        }

        vector<int> child = { x - 1, x + 1, x * 2 }; //자식 노드
        for (int i = 0; i < 3; i++) { //세 자식 노드 체크
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { //노드가 좌표 내에 있고, 아직 체크하지 않은 경우
                check[child[i]] = check[x] + 1; //해당 좌표까지 시간 설정
                q.push(child[i]); //큐에 좌표 저장
            }
        }
    }
    return ans; //계산 끝난 후 반환
}

/**
 * [숨바꼭질]
 *
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    int n, k; //수빈이의 위치, 동생의 위치

    //입력
    cin >> n >> k; //각 위치 입력

    //연산 & 출력
    cout << bfs(n, k); //가장 빠른 시간 계산해 출력
    return 0;
}