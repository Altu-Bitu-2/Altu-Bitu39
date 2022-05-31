#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find ����
int findParent(int node) {
    if (parent[node] < 0) { //���� ������� ��Ʈ �����̹Ƿ�
        return node; //�״�� ��ȯ
    }
    return parent[node] = findParent(parent[node]); //��� ��Ʈ ���� ã��
}

//Union ����
bool unionInput(int x, int y) {
    int xp = findParent(x); //x�� ��Ʈ ���� ã��
    int yp = findParent(y); //y�� ��Ʈ ���� ã��

    if (xp == yp) { //��Ʈ ������ ���ٸ�
        return false; //false ��ȯ(union �Ұ���, ����Ŭ �������)
    }
    if (parent[xp] < parent[yp]) { //xp�� �θ� �� �۴ٸ�
        parent[xp] += parent[yp]; //xp�� �θ� ���� ���ϰ�(ũ��)
        parent[yp] = xp; //xp�� yp�� ���ο� ��Ʈ��
    }
    else { //�׷��� �ʴٸ�
        parent[yp] += parent[xp]; //yp�� �θ� ���� ���ϰ�(ũ��)
        parent[xp] = yp; //yp�� xp�� ���ο� ��Ʈ��
    }
    return true; //union �� �� �ܰ� ����Ŭ x
}

/**
 * [����Ŭ ����]
 *
 * ����Ŭ�� �߻��� ���� = ���� ���տ� �ִ� ���� �� ���� ���Ͽ��Ϸ� �� ��
 * unionInput �Լ��� ��ȯ���� bool�� �����Ͽ� cycle�� �����Ǵ� ���� �߰��ϱ�
 */

int main() {
    int n, m, x, y; //���� ����, ����� ������ ��, �� ��

    //�Է�
    cin >> n >> m; //�� ����, ���� �� �Է�
    parent.assign(n, -1); //�� ���� ����ŭ ����� -1�� �ʱ�ȭ
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //�� �� �Է�

        //���� & ���
        if (!unionInput(x, y)) { //����Ŭ�� ������
            cout << i + 1; //�ش� ���� ���
            return 0;
        }
    }
    cout << 0; //����Ŭ�� �������� ���� ��� 0 ����ϰ� ����
    return 0;
}