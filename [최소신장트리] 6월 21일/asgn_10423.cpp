#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find ����
int findParent(int x) {
    if (parent[x] < 0) { //�θ� �������
        return x; //��Ʈ �����̹Ƿ� �״�� ��ȯ
    }
    return parent[x] = findParent(parent[x]); //��� �θ� ã��
}

//Union ����
bool unionNodes(int x, int y) {
    int px = findParent(x); //x�� �θ�
    int py = findParent(y); //y�� �θ�

    if (px == py) { //�θ� ���ٸ�
        return false; //�̹� ���� ����, ������ �ʿ� �����Ƿ� false ��ȯ
    }
    if (parent[px] < parent[py]) { //���ο� ��Ʈ px
        parent[px] += parent[py]; //px�� �θ� ũ�� �����ְ�
        parent[py] = px; //px�� py�� ���ο� ��Ʈ�� ����
    }
    else { //���ο� ��Ʈ py
        parent[py] += parent[px]; //py�� �θ� ũ�� �����ְ�
        parent[px] = py; //py�� px�� ���ο� ��Ʈ�� ����
    }
    return true; //���������Ƿ� true ��ȯ�� ���� ��, ��� ����� �� �ֵ���
}

int kruskal(int n, vector<tp>& edges) {
    int sum = 0, cnt = 0; //�ּ� ���, ���� �� �ʱ�ȭ
    for (int i = 0; i < edges.size(); i++) {
        int w = get<0>(edges[i]); //���ĵ� edge���� ���� ����
        int u = get<1>(edges[i]); //������ ���� ��������
        int v = get<2>(edges[i]);
        if (!unionNodes(u, v)) { //���� ����, �� ���ð� �̹� ����Ǿ� �ִٸ�
            continue; //���ο� �ݺ�
        }
        sum += w; //�ּ� ��� ++
        cnt++; //���� �� ++
        if (cnt == n - 1) { //���� �����ߴٸ�
            return sum; //�ּ� ��� ��ȯ
        }
    }
    return 0;
}

/**
 * [���Ⱑ ������]
 *
 * ��� ���ÿ� ���Ⱑ ���޵� �� �ֵ��� �ּ� ������� ���ø� �����ϴ� ����
 * �� ������ k���� �ּҽ���Ʈ���� ������ ������, �����Ⱑ �ִ� ���ø� ��� ������ ������ �����Ѵٰ� �����ϸ� �ϳ��� ū Ʈ���� �̷�
 *
 * -> �ѹ��� ũ�罺Į �˰������� �ذ� ����
 */
int main() {
    int n, m, k, u, v, w; //���� ����, ��ġ ���� ���̺� ��, ������ ����, u-v ���� ���� �� ��� w

    //�Է�
    cin >> n >> m >> k; //����, ���̺�, ������ ���� �Է�
    vector<tp> edge; //���̺� ���� ���� ����
    parent.assign(n + 1, -1); //�� ���� -1�� �ʱ�ȭ
    for (int i = 0; i < k; i++) {
        cin >> u; //������ ��ġ�� ���� ��ȣ �Է�
        parent[u] = 0; //0�� ������ ����ƴٰ� ����
    }
    while (m--) { //�� ���̺�
        cin >> u >> v >> w; //���� �� ���ÿ� ��ġ ��� �Է�
        edge.push_back({ w, u, v }); //���Ϳ� ���
    }

    //����
    sort(edge.begin(), edge.end()); //���̺� ��� �� ����

    //���� & ���
    cout << kruskal(n - k + 1, edge); //k���� ������ �̹� ����� �����̹Ƿ� n - k���� ������ �����ص� ��
    return 0;
}