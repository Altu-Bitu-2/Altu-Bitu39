#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

//위상정렬
vector<int> topologicalSort(int t, int n, vector<int>& indegree, matrix& resources, matrix& graph) {
    queue<pair<int, int>> q; //first:진입차수가 0인 건물, second:시간
    vector<bool> check(n + 1, false); //생산 자원 체크 배열
    vector<int> result; //반환할 가능한 건물

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { //진입차수가 있다면
            q.push({ i, 0 }); //큐에 넣기, 걸리는 시간은 0으로 초기화
        }
    }
    while (!q.empty()) { //큐에 건물이 있다면
        int x = q.front().first; //큐에서 가져오기
        int curr_t = q.front().second; //시간 초과 계산을 위함
        q.pop(); //큐에서 팝

        if (curr_t > t) { //시간 초과 시
            break; //다음 반복
        }
        result.push_back(x); //가능한 건물에 추가
        for (int i = 0; i < resources[x].size(); i++) {
            int resource = resources[x][i]; //생산하는 자원
            if (check[resource]) { //체크했다면
                continue; //다음 반복으로
            }
            check[resource] = true;
            for (int j = 0; j < graph[resource].size(); j++) {
                int building = graph[resource][j]; //필요로 하는 자원
                indegree[building]--; //진입차수 줄이기
                if (!indegree[building]) { //진입차수 아직 남아있다면
                    q.push({ building, curr_t + 1 }); //시간 +1로 큐에 넣기
                }
            }
        }
    }
    return result; //완성된 가능 건물 반환
}

/**
 * [쿠키런 킹덤]
 *
 * 건물마다 필요로 하는 자원의 관계를 그래프로 표현하여 위상정렬을 사용해 제한 시간(t) 이내에 지을 수 있는 건물들을 구함
 * - 그래프 관계: 필요로 하는 자원 -> 건물
 * - 이때, 각 건물마다 생산하는 자원이 여러 개이므로 위상정렬에서 연결된 정점의 진입차수를 감소하는 부분에서 생산하는 자원을 모두 검사해야 함
 * - 위 과정에서 서로 다른 건물끼리 생산하는 자원이 겹칠 수 있으므로, 이미 생산한 자원은 체크를 해줌
 * - 위상정렬하다 제한 시간을 넘으면 종료
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t, cnt, resource, building; //자원 가짓수, 이미 지어진 건물 수, 제한 시간, 자원 가짓수, 자원과 건물 입력

    //입력
    cin >> n >> m >> t; //자원 가짓수, 지어진 건물 수, 제한시간 입력
    vector<int> indegree(n + 1, 0); //진입차수 배열
    matrix graph(n + 1, vector<int>(0)); //자원 그래프
    matrix resources(n + 1, vector<int>(0)); //각 건물이 생산하는 자원들
    for (int i = 0; i < m; i++) { //이미 지어진 건물
        cin >> building;
    }
    for (int i = 1; i <= n; i++) { //건물이 생산하는 자원
        cin >> cnt; //생산 가능한 자원 가짓수
        while (cnt--) {
            cin >> resource; //자원 번호
            resources[i].push_back(resource); //자원 배열에 넣기
        }
    }
    for (int i = 0; i < n - m; i++) { //건물마다 필요한 자원
        cin >> building >> cnt; //아직 지어지지 않은 건물 번호, 필요로 하는 자원 가짓수 입력
        indegree[building] = cnt; //필요로 하는 자원 가짓수를 진입차수로 입력
        while (cnt--) {
            cin >> resource; //자원 번호 입력
            graph[resource].push_back(building); //그래프에 넣기
        }
    }

    //연산
    vector<int> result = topologicalSort(t, n, indegree, resources, graph); //제한 시간 내에 지을 수 있는 건물 개수 계산
    sort(result.begin(), result.end()); //오름차순 정렬

    //출력
    cout << result.size() << '\n'; //가능한 건물 개수 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' '; //가능한 건물 번호 출력
    }
    return 0;
}