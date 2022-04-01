#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */
void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        return; //최종적인 반환값이 최소 비용이 아닐 수 있음
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { //마지막 도시에서 출발 도시로 갈 수 있다면
            ans = min(ans, cost + matrix[cur_city][0]); //비용으로 저장
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; //방문한 것으로 설정
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); //재귀를 통해 다음 방문 도시 결정
            visited[i] = false; //순회가 끝난 경우 다음 탐색을 위해 돌려놓기
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n; //도시 수
    visited.assign(n, false); //도시 방문 여부 벡터
    matrix.assign(n, vector<int>(n, 0)); //방문 비용 벡터
    for (int i = 0; i < n; i++) { //방문 비용 입력
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //연산
    visited[0] = true; //출발 도시
    backtracking(1, 0, 0);

    //출력
    cout << ans; //최소 비용 출력
    return 0;
}