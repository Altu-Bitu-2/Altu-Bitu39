#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tieNumber(vector<int>& arr) {
    int total = 0; //���� �ʱ�ȭ
    int size = arr.size(); //����
    for (int i = 0; i < size - 1; i += 2) { //���� ū ������ ���� ������
        total += arr[i] * arr[i + 1];
    }
    //�ϳ� ���� �� ������
    if (size % 2) {
        total += arr[size - 1];
    }
    return total; //���� ��ȯ
}

/**
 * [�� ����]
 *
 * 1. ����� �������, ������ �������� ���ؾ� ū ���� ���� �� �ִ�.
 * 2. ������ ū �ͳ��� ���ؾ� �� ū ���� ���� �� �ִ�.
 *     ex) 1, 2, 3, 4 => 4 * 1 + 3 * 2 = 10
 *                    => 4 * 3 + 2 * 1 = 14
 * 3. 1�� ���ϴ� �ͺ��� ���ؾ� ū ���� ���� �� �ִ�. (x * 1 = x < x + 1)
 */
int main() {
    int n, x, cnt1 = 0; //������ ũ��, ������ �� ��, 1 ī��Ʈ �ʱ�ȭ

    //�Է�
    cin >> n; //���� ũ�� �Է�
    vector<int> arr_pos, arr_neg; //��� ����, ���� ����
    while (n--) { //���� ���� �� ������
        cin >> x; //������ �� �Է�
        if (x > 1) { //���
            arr_pos.push_back(x); //���Ϳ� �ֱ�
        }
        else if (x < 1) { //���ϸ� �۾����� ��� or ����
            arr_neg.push_back(x); //���Ϳ� �ֱ�
        }
        else { //1
            cnt1++;
        }
    }

    //������ ū ������ ����
    sort(arr_pos.begin(), arr_pos.end(), greater<>()); //��� ����
    sort(arr_neg.begin(), arr_neg.end()); //�۾����� ��� or ���� ����

    //���� & ���
    cout << cnt1 + tieNumber(arr_pos) + tieNumber(arr_neg); //���ϰ� ���� �ִ��� ���
    return 0;
}