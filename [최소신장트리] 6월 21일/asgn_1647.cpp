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
        return false; //�̹� ����Ǿ� �����Ƿ� false
    }
    if (parent[px] < parent[py]) { //���ο� ��Ʈ px
        parent[px] += parent[py]; //px�� �θ� ũ�� ���ϰ�
        parent[py] = px; //py�� ���ο� ��Ʈ�� ����
    }
    else { //���ο� ��Ʈ py
        parent[py] += parent[px]; //py�� �θ� ũ�� ���ϰ�
        parent[px] = py; //px�� ���ο� ��Ʈ ����
    }
    return true; //���������Ƿ� true ��ȯ
}

int kruskal(int n, vector<tp>& edge) {
    int sum = 0, cnt = 0; //�ּ� ������, ���� �� �ʱ�ȭ
    for (int i = 0; i < edge.size(); i++) {
        int w = get<0>(edge[i]); //���ĵ� edge���� �������
        int u = get<1>(edge[i]); //������ �� ��������
        int v = get<2>(edge[i]);
        if (!unionNodes(u, v)) { //�� ����, �� ���� �̹� ����Ǿ� �ִٸ�
            continue; //���ο� �ݺ�
        }
        sum += w; //�ּ� ������++
        cnt++; //���� �� ++
        if (cnt == n - 1) { //���� ���� ��
            return sum; //�ּ� ������ ��ȯ
        }
    }
    return 0;
}

/**
 * [���� ���� ��ȹ]
 *
 * ������ �ΰ��� �и��ϰ�, �� ������ �̵��� �� �ִ� �ּ����� ���θ� ����� ����
 * ��, 2���� �ּҽ���Ʈ���� ������ �ϴ� ����
 * -> �ϳ��� �ּҽ���Ʈ���� �����, �� �� ���� ������ ū ���θ� ����
 * -> ũ�罺Į �˰��򿡼� ���� �������� �����Ǵ� ���ΰ� ������ ���� ŭ
 * -> ũ�罺Į �˰��򿡼� ������ n-2���� �����Ͽ� �� ���� ���Ͽ� �ذ�
 */
int main() {
    int n, m, a, b, c; //�� ����, �� ����, a-b ������ c

    //�Է�
    cin >> n >> m; //��, �� ���� �Է�
    vector<tp> edge; //�� ������ ���� ����
    parent.assign(n + 1, -1); //-1�� �ʱ�ȭ
    while (m--) { //�� �渶�� �ݺ�
        cin >> a >> b >> c; //������ ��, �� ������ �Է�
        edge.push_back({ c, a, b }); //edge ���Ϳ� �ֱ�
    }

    //����
    sort(edge.begin(), edge.end()); //������ �� ����

    //����&���
    cout << kruskal(n - 1, edge); //�ּ� ������ ����� ���
    return 0;
}