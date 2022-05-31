#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find ����
int findParent(int node) {
    if (parent[node] < 0) { //�θ� �������
        return node; //��Ʈ �����̹Ƿ� �״�� ��ȯ
    }
    return parent[node] = findParent(parent[node]); //��� �θ� ã��
}

//Union ����
void unionInput(int x, int y) {
    int xp = findParent(x); //x�� �θ�
    int yp = findParent(y); //y�� �θ�

    if (xp == yp) { //�θ� ���ٸ�
        return; //�̹� ���� ���տ� ����
    }
    if (parent[xp] < parent[yp]) { //yp�� �θ� �� ũ�ٸ�
        parent[xp] += parent[yp]; //xp�� �θ� ���� ���ϰ�(ũ��)
        parent[yp] = xp; //xp�� yp�� ���ο� ��Ʈ��
    }
    else { //�׷��� �ʴٸ�
        parent[yp] += parent[xp]; //yp�� �θ� ���� ���ϰ�(ũ��)
        parent[xp] = yp; //yp�� xp�� ���ο� ��Ʈ��
    }
}

int liarParty(vector<int>& parties) {
    int cnt = 0; //�������� ��Ƽ ī��Ʈ �ʱ�ȭ
    for (int i = 0; i < parties.size(); i++) { //�� ��Ƽ
        if (findParent(parties[i]) != findParent(0)) { //�ش� ��Ƽ�� ��Ʈ�� 0���� ������ �ƴ� ���
            cnt++; //������ ����
        }
    }
    return cnt; //ī��Ʈ ��ȯ
}

/**
 * [������]
 *
 * 1. �� ������� �پ��� ��Ƽ�� ���� ����ƴٰ� �� �� ����
 * 2. ����� ������� ���� ���տ� ����
 * 3. �� ���տ� ���� ����� �� �� ���̶� ������ �ȴٸ� �� ������ ������� ���� ��Ƽ���� �������� �� �� ����
 * -> ���Ͽ� ���ε�� ������� �������� ���� ��, ��Ƽ���� �������� �� �� �ִ��� Ȯ���ϱ�
 * -> �̶�, ������ �ƴ� ������� ��Ʈ ������ 0���� �����ؼ� ���Ͽ� ���ε带 ���� �������� ���� ����
 * -> 0�� ���� ������ �ƴϾ�� �������� �� �� ����
 *
 * !����! ��Ƽ ������ �Է¹����� �ٷ� ������ ���� ���θ� �Ǵ��� �� ���� (���� �Է� 4)
 *       �� ��Ƽ���� �� ����� �����ص� ��, �������� ������ ���� ���� �� ���� �Ǵ�
 */

int main() {
    int n, m; //����� ��, ��Ƽ�� ��

    //�Է�
    cin >> n >> m; //���, ��Ƽ �� �Է�
    parent.assign(n + 1, -1); //-1�� �ʱ�ȭ

    int init, p; //������ �ƴ� ����� ��, ��ȣ
    cin >> init; //������ �ƴ� ��� �� �Է�
    while (init--) { //������ �ƴ� �����
        cin >> p; //������ �ƴ� ����� ��ȣ �Է�
        unionInput(0, p); //������ �ƴ� ����� ��Ʈ ������ 0���� ����
    }

    int cnt, first_person, person; //�� ��Ƽ�� ���� ����� ��, ��ȣ��
    vector<int> parties; //��Ƽ ����
    while (m--) { //��� ��Ƽ ����� ����
        cin >> cnt >> first_person; //��Ƽ ��� ��, ù ��ȣ

        //����
        parties.push_back(first_person); //��Ƽ ������ �� ��Ƽ�� ù��° ����� ����
        while (--cnt) { //��� ��� ����� ����
            cin >> person; //�ٸ� ��ȣ�� �Է�
            unionInput(first_person, person); //�� ��Ƽ�� ���� �����
        }
    }

    //���� & ���
    cout << liarParty(parties); //������ ������ ��Ƽ �� ����� ���
    return 0;
}