#include <iostream>
#include <cmath>

using namespace std;

// ��Ŭ���� ȣ����
int gcdRecursion(int a, int b) {
    // a > b �� ��, a�� b�� �ִ������� ����
    if (b == 0) { //b�� 0�̶��
        return a; //0���� ���� �� ����, a ����
    }
    return gcdRecursion(b, a % b); //��ͷ� �ִ����� ��ȯ
}

/**
 * �ִ������� G, �ּҰ������ L �̶�� ����.
 * G*L = A*B �̰�
 * A = G*a, B = G*b�� ��Ÿ�� �� �ִ�.
 * �̿� ���� G*L = G*G*a*b�� �� �� �ְ� �̸� �����ϸ�
 * L/G = a*b �̴�.
 *
 * A+B�� �ּҰ� �Ƿ���, a+b�� �ּҰ� �Ǿ�� �ϰ�, �׷��� ���ؼ� a, b�� ���̰� �ּҿ��� �Ѵ�.
 */

int main() {
    int gcd, lcm;

    //�Է�
    cin >> gcd >> lcm; //�ִ�����, �ּҰ���� �Է�

    //����
    int ab = lcm / gcd;
    int a = -1, b = -1;
    for (int i = sqrt(ab); i > 0; i--) { //a, b�� ���̰� ���� ���� �����ٺ��� üũ
        if (ab % i != 0) { //a�� ������� üũ
            continue;
        }
        //i�� ab�� ������
        int tmp_a = i, tmp_b = ab / i; //���μ� üũ�� ����
        //�� ���� ���μ����� üũ -> ���� �� ���� ���μҰ� �ƴ϶�� �� ���� �ִ������� gcd�� �� �� ����
        if (gcdRecursion(tmp_b, tmp_a) == 1) { //�� ���� �ִ������� 1�̶��
            a = tmp_a;
            b = tmp_b;
            break; //�� �ڿ��� Ȯ�� �� �ݺ��� ������
        }
    }

    //���
    cout << a * gcd << ' ' << b * gcd; //���� �ּҰ� �ǵ��� ����� ���

    return 0;
}