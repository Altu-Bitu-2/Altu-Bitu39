#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N��° ū ��]
 *
 * �޸� ������ �����Ƿ�, �Է°��� ��� �����ϸ� �ȵȴ�.
 * ���� n���� �����ϴ� "�ּ�" ���� ���� heap[0]�� ��������� N��° ū���� �����ϴ� Ǯ��
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    priority_queue<int, vector<int>, greater<>> pq; //�ּ� ��, �����̶� �ݴ�

    cin >> n; //n �Է�
    int size = n * n;
    while (size--) {
        //�Է�
        cin >> input; //�ϴ� input�� �ް�

        //����
        pq.push(input); //�ְ� ū ������ ������ ��
        if (pq.size() > n) { //�ּ� ���� ũ�Ⱑ n �̻��̶�� ���� ���� �� ����
            pq.pop();
        }
    }

    //���
    cout << pq.top(); //���� �� = �ִ�
    return 0;
}