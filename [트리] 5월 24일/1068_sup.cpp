#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int& erase_node) {
    //부모가 없는 노드(트리 맨위 노드)를 지운다면
    if (node == erase_node) { 
        return 0; //아래 노드가 전부 사라지므로 0 출력
    }
    //tree가 비어있거나 1개만 존재하는데 지울 노드라면
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1; //root만 존재하므로 1 출력
    }
    int cnt = 0; //카운트 초기화
    for (int i = 0; i < tree[node].size(); i++) { //재귀를 통해 계속 지워가면서 리프 노드 수 ++
        cnt += eraseLeafCnt(tree[node][i], erase_node);
    }
    return cnt; //지금까지 계산한 리프 노드 수 반환
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node; //노드 개수, 각 노드의 부모, 부모가 없는 노드, 지울 노드 번호

    //입력
    cin >> n; //노드 개수 입력
    tree.assign(n, vector<int>(0)); //각 노드 부모 관리용
    for (int i = 0; i < n; i++) { //각 노드 부모 정리
        cin >> par; //각 노드 부모 입력
        if (par == -1) { //부모가 없는 노드라면
            root = i; //root
            continue; //tree에 넣지 않고 이어감
        }
        tree[par].push_back(i); //tree에 넣기
    }
    cin >> erase_node; //지울 노드 입력

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node); //노드를 지운 후 리프 노드 계산해 출력
    return 0;
}