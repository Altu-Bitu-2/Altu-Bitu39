#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int x) {
    if (parent[x] < 0) { //부모 음수인 경우
        return x; //루트 정점이므로 그대로 부모 반환
    }
    return parent[x] = findParent(parent[x]); //아닌 경우 부모 찾을 때까지 재귀
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x); //x 부모
    int py = findParent(y); //y 부모

    if (px == py) { //부모 같다면
        return false; //사이클을 이루어 연결할 필요 없으므로 false 반환
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py]; //px 부모에 크기 더해주고
        parent[py] = px; //py 새롭게 루트 설정
    }
    else { //새로운 루트 py
        parent[py] += parent[px]; //py 부모에 크기 더해주고
        parent[px] = py; //px 새롭게 루트 설정
    }
    return true; //연결 했으므로 true 반환
}

int kruskal(int n, int idx, vector<tp>& edge) {
    int cnt = 0, sum = 0; //카운트, 비용 초기화
    for (int i = idx; i < edge.size(); i++) {
        int dist = get<0>(edge[i]); //가중치,
        int x = get<1>(edge[i]); //두 정점 정보 가져와 초기화
        int y = get<2>(edge[i]);
        if (!unionNodes(x, y)) { //연결 시도, 불가능한 경우
            continue; //다음 반복
        }
        sum += dist; //비용 ++
        cnt++; //카운트 ++
        if (cnt == n - 1) { //전부 연결했다면
            return sum; //비용 반환
        }
    }
    return 0; //mst를 만들 수 없음
}

/**
 * [MST 게임]
 *
 * MST 알고리즘을 여러 번 실행해도 될까?
 * 1. 크루스칼 알고리즘의 시간 복잡도는 O(ElogE)
 *    이는 오직 간선을 정렬하는 연산의 시간 복잡도!
 *    즉, 모든 간선을 한 번 정렬해서 저장해두면 이후 몇 번의 알고리즘을 수행하여도 연산 시간에 큰 영향이 없음
 * 2. 간선 재사용을 위해 우선순위 큐가 아닌 벡터에 저장하고 크루스칼 알고리즘 k번 실행
 * 3. 매번 크루스칼을 수행할 때마다 제일 먼저 추가한 간선을 제외함
 *    -> 첫번째 간선은 모든 점이 분리된 상태에서 들어오기 때문에 무조건 사용하게 되어 있고, 이는 사용한 간선 중 가장 짧은 간선
 *    -> 제외될 간선은 배열의 첫번째 간선부터 순차적 제외
 * 4. 만약 한 번 MST를 만들 수 없다는게 확인됐다면 이후에도 MST를 만들 수 없으므로 flag 변수로 불필요한 연산 절약
 */
int main() {
    int n, m, k, x, y; //정점 개수, 간선 개수, 턴 수, 간선 연결 정점 번호

    cin >> n >> m >> k; //정점, 간선, 턴 수 입력
    vector<tp> edge; //간선 정보 벡터
    for (int i = 1; i <= m; i++) {
        cin >> x >> y; //정점 번호 입력
        edge.push_back({ i, x, y }); //벡터에 넣기
    }

    bool flag = false; //연산 절약을 위한
    for (int i = 0; i < k; i++) {
        if (flag) { //더이상 mst를 만들 수 없음
            cout << 0 << ' '; //0 출력
            continue; //다음 반복(턴이 남아있다면 0 출력해야 함.
        }
        parent.assign(n + 1, -1); //초기화
        int ans = kruskal(n, i, edge); //mst 계산
        if (ans == 0) { //만들 수 없다면
            flag = true; //flag를 true로 바꿔 이후 계산 하지 않도록
        }
        cout << ans << ' '; //mst 만든 경우 출력
    }
    return 0;
}