#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬 + DP
vector<int> topologicalSort(int n, vector<int>& t, vector<int>& indegree, vector<vector<int>>& graph) {
    queue<int> q; //진입차수에 따라 계산 위함
    vector<int> dp(n + 1, 0); //동적 계획법 위한 배열

    for (int i = 1; i <= n; i++) {
        dp[i] = t[i]; //동적 계획법 위해 각 건물 시간 입력
        if (!indegree[i]) { //진입차수가 있다면 큐에 넣어 나중에 계산
            q.push(i);
        }
    }
    while (!q.empty()) { //큐에 건물이 있다면
        int node = q.front(); //하나 꺼내고
        q.pop(); //큐에서 팝

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i]; //꺼낸 건물의 다음 노드
            dp[next_node] = max(dp[next_node], dp[node] + t[next_node]); //가장 오래 걸리는 시간이 다음 노드에 필요한 시간

            indegree[next_node]--; //진입차수 줄이기
            if (!indegree[next_node]) { //아직 진입차수가 있다면
                q.push(next_node); //큐에 넣기
            }
        }
    }
    return dp;
}

/**
 * [게임 개발]
 *
 * - ACM Craft (1005) 와 동일한 문제
 * - 최소 시간 = 건물을 동시에 지을 수 있는 건 최대한 동시에 지어야 최소 시간이 걸리므로 그 전 정점 중 가장 오래 걸리는 시간을 선택
 */

int main() {
    int n, input; //건물 종류 수, 입력

    //입력
    cin >> n; //건물 종류 수 입력
    vector<int> t(n + 1, 0); //건물을 짓는데 걸리는 시간
    vector<int> indegree(n + 1, 0); //진입차수 배열
    vector<vector<int>> graph(n + 1, vector<int>(0)); //우선순위 건물 그래프
    for (int i = 1; i <= n; i++) {
        cin >> t[i]; //건물 짓는데 걸리는 시간 입력
        while (cin >> input) { //입력받기
            if (input == -1) { //-1이라면 끝
                break;
            }
            graph[input].push_back(i); //건물 그래프에 넣기
            indegree[i]++; //진입차수 카운트
        }
    }

    //연산
    vector<int> ans = topologicalSort(n, t, indegree, graph); //각 건물 최소 시간 계산

    //출력
    for (int i = 1; i <= n; i++) { //각 건물 시간 출력
        cout << ans[i] << '\n';
    }
    return 0;
}