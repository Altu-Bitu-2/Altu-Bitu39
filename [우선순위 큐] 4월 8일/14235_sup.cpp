#include <iostream>
#include <queue>

using namespace std;

/**
 * [ũ�������� ����] - �ܼ� ���� ����
 *
 * - 0�� ���� ������, ������ �ִ� ���� �� ���� ��ġ�� ū ���� ���� & ��� -> �ִ� �� �ʿ�
 */

int main() {
    int n, a, input;
    priority_queue<int> pq; //�ִ� ��

    //�Է�
    cin >> n; //���̵�&������ �湮 Ƚ��
    while (n--) {
        cin >> a; //���� ����(0�� ��� ���̵�)
        if (!a) { //���̵��� ���� ���
            if (pq.empty()) { //���� x
                cout << "-1\n";
            }
            else { //���� �ֱ�
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else { //������ �����ϴ� ���
            while (a--) {
                cin >> input;
                pq.push(input);
            }
        }
    }
    return 0;
}