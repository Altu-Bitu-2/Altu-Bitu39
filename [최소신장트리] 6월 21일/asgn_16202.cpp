#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find ����
int findParent(int x) {
    if (parent[x] < 0) { //�θ� ������ ���
        return x; //��Ʈ �����̹Ƿ� �״�� �θ� ��ȯ
    }
    return parent[x] = findParent(parent[x]); //�ƴ� ��� �θ� ã�� ������ ���
}

//Union ����
bool unionNodes(int x, int y) {
    int px = findParent(x); //x �θ�
    int py = findParent(y); //y �θ�

    if (px == py) { //�θ� ���ٸ�
        return false; //����Ŭ�� �̷�� ������ �ʿ� �����Ƿ� false ��ȯ
    }
    if (parent[px] < parent[py]) { //���ο� ��Ʈ px
        parent[px] += parent[py]; //px �θ� ũ�� �����ְ�
        parent[py] = px; //py ���Ӱ� ��Ʈ ����
    }
    else { //���ο� ��Ʈ py
        parent[py] += parent[px]; //py �θ� ũ�� �����ְ�
        parent[px] = py; //px ���Ӱ� ��Ʈ ����
    }
    return true; //���� �����Ƿ� true ��ȯ
}

int kruskal(int n, int idx, vector<tp>& edge) {
    int cnt = 0, sum = 0; //ī��Ʈ, ��� �ʱ�ȭ
    for (int i = idx; i < edge.size(); i++) {
        int dist = get<0>(edge[i]); //����ġ,
        int x = get<1>(edge[i]); //�� ���� ���� ������ �ʱ�ȭ
        int y = get<2>(edge[i]);
        if (!unionNodes(x, y)) { //���� �õ�, �Ұ����� ���
            continue; //���� �ݺ�
        }
        sum += dist; //��� ++
        cnt++; //ī��Ʈ ++
        if (cnt == n - 1) { //���� �����ߴٸ�
            return sum; //��� ��ȯ
        }
    }
    return 0; //mst�� ���� �� ����
}

/**
 * [MST ����]
 *
 * MST �˰����� ���� �� �����ص� �ɱ�?
 * 1. ũ�罺Į �˰����� �ð� ���⵵�� O(ElogE)
 *    �̴� ���� ������ �����ϴ� ������ �ð� ���⵵!
 *    ��, ��� ������ �� �� �����ؼ� �����صθ� ���� �� ���� �˰����� �����Ͽ��� ���� �ð��� ū ������ ����
 * 2. ���� ������ ���� �켱���� ť�� �ƴ� ���Ϳ� �����ϰ� ũ�罺Į �˰��� k�� ����
 * 3. �Ź� ũ�罺Į�� ������ ������ ���� ���� �߰��� ������ ������
 *    -> ù��° ������ ��� ���� �и��� ���¿��� ������ ������ ������ ����ϰ� �Ǿ� �ְ�, �̴� ����� ���� �� ���� ª�� ����
 *    -> ���ܵ� ������ �迭�� ù��° �������� ������ ����
 * 4. ���� �� �� MST�� ���� �� ���ٴ°� Ȯ�εƴٸ� ���Ŀ��� MST�� ���� �� �����Ƿ� flag ������ ���ʿ��� ���� ����
 */
int main() {
    int n, m, k, x, y; //���� ����, ���� ����, �� ��, ���� ���� ���� ��ȣ

    cin >> n >> m >> k; //����, ����, �� �� �Է�
    vector<tp> edge; //���� ���� ����
    for (int i = 1; i <= m; i++) {
        cin >> x >> y; //���� ��ȣ �Է�
        edge.push_back({ i, x, y }); //���Ϳ� �ֱ�
    }

    bool flag = false; //���� ������ ����
    for (int i = 0; i < k; i++) {
        if (flag) { //���̻� mst�� ���� �� ����
            cout << 0 << ' '; //0 ���
            continue; //���� �ݺ�(���� �����ִٸ� 0 ����ؾ� ��.
        }
        parent.assign(n + 1, -1); //�ʱ�ȭ
        int ans = kruskal(n, i, edge); //mst ���
        if (ans == 0) { //���� �� ���ٸ�
            flag = true; //flag�� true�� �ٲ� ���� ��� ���� �ʵ���
        }
        cout << ans << ' '; //mst ���� ��� ���
    }
    return 0;
}