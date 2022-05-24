#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>>& graph) {
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i].first; //다음 노드는 현 노드와 연결된 노드
        if (next_node == parent) { //다음 노드가 부모 노드라면
            continue; //이어서 반복문 돌리기
        }

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.second > len) { //기존 거리보다 길다면
            len = graph[node][i].second + dfs_search.second; //거리 갱신
            pos = dfs_search.first; //pos 갱신
        }
    }
    return { pos, len }; //pos 노드와 거리 반환
}

/**
 * [트리의 지름]
 *
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */

int main() {
    int n, p, c, w; //노드 개수, 간선 중 부모 노드, 간선 중 자식 노드, 간선 가중치

    //입력
    cin >> n; //노드 개수 입력
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //트리 vector
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        cin >> p >> c >> w; //간선 정보 입력
        graph[p].push_back({ c, w }); //부모 노드 기준
        graph[c].push_back({ p, w }); //자식 노드 기준 둘 다 입력해 무방향으로
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.first, -1, graph); //지름을 구성하는 다른 노드 찾기

    //출력
    cout << second_node.second; //트리 지름 계산해 출력
    return 0;
}