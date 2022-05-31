#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //ģ�� ���谡 ��� �ٸ� ����ڷ� ������ ���� ���� �ִ�

vector<int> parent(MAX + 1, -1);
map<string, int> people;

//Find ����
int findParent(int node) {
    if (parent[node] < 0) { //�����̸�
        return node; //��Ʈ �����̹Ƿ� �״�� ��ȯ
    }
    return parent[node] = findParent(parent[node]); //��� ��Ʈ ���� ã��
}

//Union ����
void unionInput(int x, int y) {
    int xp = findParent(x); //x�� �θ� ã��
    int yp = findParent(y); //y�� �θ� ã��

    if (xp == yp) { //�� ��Ʈ ������ ���ٸ�
        return; //�̹� ���� �����̹Ƿ� ���Ͽ� x
    }
    if (parent[xp] < parent[yp]) { //yp�� �θ� �� ũ�ٸ�
        parent[xp] += parent[yp]; //xp�� �θ� yp�� �θ� �� ���ϰ�
        parent[yp] = xp; //xp�� ���ο� ��Ʈ��
    }
    else { //�׷��� �ʴٸ�
        parent[yp] += parent[xp]; //yp�� �θ� xp�� �θ� �� ���ϰ�
        parent[xp] = yp; //yp�� ���ο� ��Ʈ��
    }
}

/**
 * [ģ�� ��Ʈ��ũ]
 *
 * 1. weighted union find -> ��Ʈ ������ ģ���� ��(���� ���� ��) ����
 * 2. ģ�� ��Ʈ��ũ�� �� �� �ִ��� ���ϱ� -> ��Ʈ ������ parent�� ����
 *
 * !����! ������ ���ڿ��� �����Ƿ� map�� Ȱ���� string�� int�� ����
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, f; //�׽�Ʈ ���̽� ����, ģ�� ���� ��
    string a, b; //�� ����� ���̵�

    //�Է�
    cin >> t; //�׽�Ʈ ���̽� �� �Է�
    while (t--) { //���� �׽�Ʈ
        int idx = 1; //������ ������ ��
        parent.assign(MAX + 1, -1); //-1�� �ʱ�ȭ

        cin >> f; //ģ�� ���� �� �Է�
        while (f--) { //ģ�� ���� ����ϱ�
            cin >> a >> b; //�� ����� ���̵�
            if (!people[a]) { //�ʿ� a�� ����� ���̵� ���ٸ�
                people[a] = idx++; //int�� ����
            }
            if (!people[b]) { //�ʿ� a�� ����� ���̵� ���ٸ�
                people[b] = idx++; //int�� ����
            }

            //����
            int x = people[a], y = people[b]; //������ �� x, y�� ����
            unionInput(x, y); //���Ͽ�

            //���
            cout << -parent[findParent(x)] << '\n'; //������ ũ�⸦ �̿��� ���
        }
    }
    return 0;
}