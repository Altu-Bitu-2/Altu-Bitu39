#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int x) {
    if (parent[x] < 0) { //부모 음수라면
        return x; //루트 정점이므로 그대로 반환
    }
    return parent[x] = findParent(parent[x]); //계속 부모 찾기
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x); //x의 부모
    int py = findParent(y); //y의 부모

    if (px == py) { //부모가 같다면
        return false; //이미 연결되어 있으므로 false
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py]; //px의 부모에 크기 더하고
        parent[py] = px; //py의 새로운 루트로 설정
    }
    else { //새로운 루트 py
        parent[py] += parent[px]; //py의 부모에 크기 더하고
        parent[px] = py; //px의 새로운 루트 설정
    }
    return true; //연결했으므로 true 반환
}

int kruskal(int n, vector<tp>& edge) {
    int sum = 0, cnt = 0; //최소 유지비, 연결 수 초기화
    for (int i = 0; i < edge.size(); i++) {
        int w = get<0>(edge[i]); //정렬된 edge에서 유지비와
        int u = get<1>(edge[i]); //연결할 집 가져오기
        int v = get<2>(edge[i]);
        if (!unionNodes(u, v)) { //집 연결, 두 집이 이미 연결되어 있다면
            continue; //새로운 반복
        }
        sum += w; //최소 유지비++
        cnt++; //연결 수 ++
        if (cnt == n - 1) { //전부 연결 시
            return sum; //최소 유지비 반환
        }
    }
    return 0;
}

/**
 * [도시 분할 계획]
 *
 * 마을을 두개로 분리하고, 각 집끼리 이동할 수 있는 최소한의 도로만 남기는 문제
 * 즉, 2개의 최소신장트리를 만들어야 하는 문제
 * -> 하나의 최소신장트리를 만들고, 그 중 가장 유지비가 큰 도로를 삭제
 * -> 크루스칼 알고리즘에서 가장 마지막에 삭제되는 도로가 유지비가 가장 큼
 * -> 크루스칼 알고리즘에서 간선을 n-2개만 선택하여 그 합을 구하여 해결
 */
int main() {
    int n, m, a, b, c; //집 개수, 길 개수, a-b 유지비 c

    //입력
    cin >> n >> m; //집, 길 개수 입력
    vector<tp> edge; //길 유지비 정보 벡터
    parent.assign(n + 1, -1); //-1로 초기화
    while (m--) { //각 길마다 반복
        cin >> a >> b >> c; //연결할 집, 길 유지비 입력
        edge.push_back({ c, a, b }); //edge 벡터에 넣기
    }

    //연산
    sort(edge.begin(), edge.end()); //유지비 순 정렬

    //연산&출력
    cout << kruskal(n - 1, edge); //최소 유지비 계산해 출력
    return 0;
}