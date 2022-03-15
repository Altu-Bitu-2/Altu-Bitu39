#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�Լ� S�� ���
int calcS(int n, vector<int> a, vector<int> b) { //S��(�ּڰ�) ��� �Լ�
    int s = 0; //�ּڰ� �ʱ�ȭ
    for (int i = 0; i < n; i++) { //�Լ� S ��� ���� for��
        s += (a[i] * b[i]); //S�� ���
    }
    return s;
}

/**
 * �������� B�� ��迭���� ����� ������, �ؾ��ϴ� ����
 * �� �迭���� ���� ū ���� ���� ���� ���� ���ؾ� �ּڰ��� ����!
 */

int main() {
    int n; //�迭 ����
    vector<int> a, b; //�迭 A, B

    //�Է�
    cin >> n; //�迭 ���� �ޱ�
    a.assign(n, 0); //�迭 ���� ����, �ʱ�ȭ
    b.assign(n, 0); //�迭 ���� ����, �ʱ�ȭ
    for (int i = 0; i < n; i++) { //�迭A �Է� ���� for��
        cin >> a[i]; //�迭A ���� �Է�
    }
    for (int i = 0; i < n; i++) { //�迭B �Է� ���� for��
        cin >> b[i]; //�迭B ���� �Է�
    }

    //����
    sort(a.begin(), a.end()); //�������� ����
    sort(b.begin(), b.end(), greater<>()); //�������� ����
    int result = calcS(n, a, b); //�ּڰ� ����� result�� ����

    //���
    cout << result; //�ּڰ� ���
    return 0;
}