#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {
    priority_queue<int, vector<int>, greater<>> pq; //최소힙
    vector<int> result; //반환할 배열

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { //진입차수 있다면
            pq.push(i); //힙에 넣기
        }
    }
    while (!pq.empty()) {
        int node = pq.top(); //힙에서 하나 가져오고
        pq.pop(); //빼기

        result.push_back(node); //먼저 풀어야 할 문제
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i]; //다음 노드
            indegree[next_node]--; //진입차수 없애기
            if (!indegree[next_node]) { //진입차수 있다면
                pq.push(next_node); //힙에 넣어 계산할 수 있도록
            }
        }
    }
    return result; //문제 순서 반환
}

/**
 * [문제집]
 *
 * - 조건 1, 2까지는 평범한 위상정렬
 * - 조건 3 "가능하면 쉬운 문제부터 풀어야 한다." -> 위상정렬 시, 정점이 작은 순서부터
 * - 조건 3을 만족시키기 위해, 진입차수가 0인 정점을 담는 컨테이너로 우선순위 큐 사용
 */

int main() {
    int n, m, a, b; //문제 수, 먼저 푸는 것이 좋은 문제에 대한 정보 개수, 정보 순서쌍 a, b

    //입력
    cin >> n >> m; //문제 수, 정보 수 입력
    vector<int> indegree(n + 1, 0); //진입차수 벡터
    vector<vector<int>> graph(n + 1, vector<int>(0)); //위상정렬 그래프
    while (m--) {
        cin >> a >> b; //정보 순서쌍 입력
        graph[a].push_back(b); //a->b
        indegree[b]++; //b의 진입차수 ++
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph); //위상정렬 계산

    //출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' '; //문제 순서 출력
    }
    return 0;
}