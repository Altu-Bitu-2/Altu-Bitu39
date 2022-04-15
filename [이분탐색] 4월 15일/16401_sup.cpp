#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int childNum(int len, vector<int>& snacks) {
    int cnt = 0;
    for (int i = snacks.size() - 1; i >= 0; i--) { //���� �� ���ں��� �˻�
        if (snacks[i] < len) { //�������ַ��� ���̺��� �۾����� �� �̻� �� ������
            break;
        }
        cnt += (snacks[i] / len); //�ش� ���ڸ� �� ���� �������� �� �ִ��� ī��Ʈ
    }

    return cnt;
}

int upperSearch(int left, int right, int target, vector<int>& snacks) {
    while (left <= right) {
        int mid = (left + right) / 2; //������ ����
        int cnt = childNum(mid, snacks); //���� ���̰� mid�� �� �� ���� �����ִ���

        if (cnt >= target) { //target���� �� ���� ���̵鿡�� �����شٸ� -> ���� ���̸� �� �ø� �� ����
            left = mid + 1;
        }
        else { //�� ���� ���̵��̶�� ���̸� ���̱�
            right = mid - 1;
        }
    }
    return left - 1;
}

/**
 * [���� �����ֱ�]
 *
 * n���� ���ڰ� ���� �� m���� ��ī���� ���� ���� ���̷� �� �� �ִ� ������ �ִ� ���̸� ���ϴ� ����
 * -> Ư�� ���� ���̿� ���Ͽ� m���� ��ī���� ������ �� �� �ִ°�?
 *
 * left: ���� ������ �ּڰ� -> 1
 * right: ���� ������ �ִ�
 *
 * ���ڸ� �� ���� �������� �� �ִ��� ���ʷ� �˻��ϴ� �������� �� ������ ���������� ���� ������ ���� ���ָ� ����
 */

int main() {
    int m, n, left = 1, right = 0;

    //�Է�
    cin >> m >> n; //��ī ��, ���� ��
    vector<int> snacks(n, 0);
    for (int i = 0; i < n; i++) { //�� ������ ����
        cin >> snacks[i];
    }

    //����
    sort(snacks.begin(), snacks.end()); //���� ���� ����
    right = snacks[n - 1]; //���� ���� �ִ�

    //���� & ���
    cout << upperSearch(left, right, m, snacks);
    return 0;
}