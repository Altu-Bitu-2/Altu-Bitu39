#include <iostream>

using namespace std;

// ��Ŭ���� ȣ����
int gcdRecursion(int a, int b) {
    // a > b �� ��, a�� b�� �ִ������� ����
    if (b == 0) { //b�� 0�� ���
        return a; //0���δ� �����Ⱑ �Ұ���, a ����
    }
    return gcdRecursion(b, a % b); //��� Ȱ���� �ִ����� ���ϱ�
}

int main() {
    string s;

    //�Է�
    cin >> s; //�� �Է�

    //����(�Է����κ��� n, m �����ϱ�)
    int index = s.find(':'); //':' ��ġ ã��
    int n = stoi(s.substr(0, index)); //: ������ ���ڸ� ���ڷ� ������ n������ ����
    int m = stoi(s.substr(index + 1, s.length())); //: ���� ���ڸ� ���ڷ� ������ m������ ����

    //�ִ����� ���ϱ�
    int g = gcdRecursion(max(n, m), min(n, m));

    //���
    cout << n / g << ':' << m / g << '\n';

    return 0;
}