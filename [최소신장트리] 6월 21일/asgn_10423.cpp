#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int x) {
    if (parent[x] < 0) { //부모가 음수라면
        return x; //루트 정점이므로 그대로 반환
    }
    return parent[x] = findParent(parent[x]); //계속 부모 찾기
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x); //x의 부모
    int py = findParent(y); //y의 부모

    if (px == py) { //부모가 같다면
        return false; //이미 같은 집합, 연결할 필요 없으므로 false 반환
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py]; //px의 부모에 크기 더해주고
        parent[py] = px; //px를 py의 새로운 루트로 설정
    }
    else { //새로운 루트 py
        parent[py] += parent[px]; //py의 부모에 크기 더해주고
        parent[px] = py; //py를 px의 새로운 루트로 설정
    }
    return true; //연결했으므로 true 반환해 연결 수, 비용 계산할 수 있도록
}

int kruskal(int n, vector<tp>& edges) {
    int sum = 0, cnt = 0; //최소 비용, 연결 수 초기화
    for (int i = 0; i < edges.size(); i++) {
        int w = get<0>(edges[i]); //정렬된 edge에서 연결 비용과
        int u = get<1>(edges[i]); //연결할 도시 가져오기
        int v = get<2>(edges[i]);
        if (!unionNodes(u, v)) { //도시 연결, 두 도시가 이미 연결되어 있다면
            continue; //새로운 반복
        }
        sum += w; //최소 비용 ++
        cnt++; //연결 수 ++
        if (cnt == n - 1) { //전부 연결했다면
            return sum; //최소 비용 반환
        }
    }
    return 0;
}

/**
 * [전기가 부족해]
 *
 * 모든 도시에 전기가 공급될 수 있도록 최소 비용으로 도시를 연결하는 문제
 * 이 문제는 k개의 최소신장트리를 만들어야 하지만, 발전기가 있는 도시를 모두 가상의 정점에 연결한다고 생각하면 하나의 큰 트리를 이룸
 *
 * -> 한번의 크루스칼 알고리즘으로 해결 가능
 */
int main() {
    int n, m, k, u, v, w; //도시 개수, 설치 가능 케이블 수, 발전소 개수, u-v 도시 연결 시 비용 w

    //입력
    cin >> n >> m >> k; //도시, 케이블, 발전소 개수 입력
    vector<tp> edge; //케이블 관련 정보 벡터
    parent.assign(n + 1, -1); //각 도시 -1로 초기화
    for (int i = 0; i < k; i++) {
        cin >> u; //발전소 설치된 도시 번호 입력
        parent[u] = 0; //0번 정점과 연결됐다고 생각
    }
    while (m--) { //각 케이블
        cin >> u >> v >> w; //연결 할 도시와 설치 비용 입력
        edge.push_back({ w, u, v }); //벡터에 담기
    }

    //연산
    sort(edge.begin(), edge.end()); //케이블 비용 순 정렬

    //연산 & 출력
    cout << kruskal(n - k + 1, edge); //k개의 정점은 이미 연결된 상태이므로 n - k개의 간선만 선택해도 됨
    return 0;
}