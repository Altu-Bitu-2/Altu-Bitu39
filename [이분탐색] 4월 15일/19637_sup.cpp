#include <iostream>
#include <map>

using namespace std;

/**
 * [IF�� �� ��� ����]
 *
 * ��� ĳ���Ϳ� Īȣ�� ��Ī�ϴ� ���Ʈ ������ ����ϱ⿣ �ִ� ���� Ƚ�� 10^5 * 10^5 -> 100��!
 * Ư�� ������ '����'���� �ش��ϴ� Īȣ�� ���� �� ����
 * -> �̺� Ž��
 *
 * �ʰ� ���� ���Ҹ� ���ĵ� ���·� �����ϱ� ������ �˰��� ��� ���� ��ü������ �̺� Ž�� �Լ��� ����� �� ����
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //Īȣ�� �� Īȣ�� ������ ���Ѱ�

    int n, m, power;
    string name;

    //�Է�
    cin >> n >> m; //Īȣ�� ����, ĳ���� ����
    while (n--) {
        cin >> name >> power; //Īȣ�� �̸�, ������ ���Ѱ�
        if (title[power].empty()) { //Īȣ�� ���� ���� ��츦 ����
            title[power] = name;
        }
    }

    //���
    while (m--) {
        cin >> power; //ĳ������ ������ �Է�
        cout << title.lower_bound(power)->second << '\n';
    }
}