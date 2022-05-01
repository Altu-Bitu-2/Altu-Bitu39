#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//���� ������ �˻��ϴ� �Լ�(�� ������)
bool isGood(vector<int>& num, int left, int right, int idx) {
    while (left < right) { //���� ���� ������
        if (left == idx) { //����� ���� left�� ��ĥ ���
            left++; //left �ű��
            continue;
        }
        if (right == idx) { //����� ���� right�� ��ĥ ���
            right--; //right �ű��
            continue;
        }

        if (num[left] + num[right] == num[idx]) { //left+right�� ����� ���� ���
            return true; //true�� ������ ī��Ʈ�ϵ���
        }
        if (num[left] + num[right] > num[idx]) { //left+right�� ����� ������ ū ���
            right--; //right�� �Ű� �� ���� ���� �ǵ���
        }
        else { //left+right�� ����� ������ ���� ���
            left++; //left�� �Ű� �� ū ���� �ǵ���
        }
    }
    return false; //true�� �ش����� �ʴ´ٸ� false ������ ī��Ʈ���� �ʵ��� ��
}

/**
 * [����]
 *
 * 1. �� ������ �� �� ������ �����͸� �����ؼ� �������鼭 � '�ٸ� �� ��'�� ���� ���� ���� �� �ִ��� �˻�
 * 2. �����͸� ���ʷ� �ű�� �˻��ϱ� ���� �̸� ���� �������� ������
 * 3. ���� ������� ���� ��ġ�� left, right ������ ��ġ�� ��ĥ ��� ó�� ����
 */

int main() {
    int n, ans = 0; //���� ����, good ���� ī��Ʈ �ʱ�ȭ

    //�Է�
    cin >> n; //���� ���� �Է�
    vector<int> num(n, 0); //�ִ� �� ����
    for (int i = 0; i < n; i++) { //�� �� �Է�
        cin >> num[i];
    }

    //����
    sort(num.begin(), num.end()); //�������� ����
    for (int i = 0; i < n; i++) { //�� ���� �Ǻ��ϱ� ���� for��
        if (isGood(num, 0, n - 1, i)) { //�� �� �Ǻ�
            ans++; //good�̶�� ī��Ʈ
        }
    }

    //���
    cout << ans; //good ���� ���
    return 0;
}