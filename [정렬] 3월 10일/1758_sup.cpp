#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calTip(int n, vector<int>& tips) { //�� ��� �Լ�
    long long ans = 0; //��ȯ�� ��
    for (int i = 0; i < n; i++) { //�մ��� �� ���+�հ� �г�Ƽ for��
        int cur_tip = tips[i] - i; //���� �г�Ƽ
        if (cur_tip < 0) //������ ���� ������ �ʴµ� ó���� �������� ���������Ƿ� �ƿ� break
            break;
        ans += cur_tip; //�� �հ�
    }
    return ans; //�� ��ȯ
}

/**
 * ��ȣ�� ���� �� �ִ� ���� �ִ��� �Ƿ��� ���� ���� ����� ������ ���ƾ���
 * !����! �־����� N�� �ִ� ũ�Ⱑ 100,000�̰� ���� �ִ� ũ�Ⱑ 100,000�̹Ƿ�
 *       ������ �ִ��� 10^5 * (10^5+1) / 2�� int ������ �ѱ� ������ long long �� ��� ��
 */

int main() { //���� �Լ�
    int n; //�մ� ��

    //�Է�
    cin >> n; //�մ� ��
    vector<int> tips(n, 0); //�մԺ� ���� �Է¹��� vector
    for (int i = 0; i < n; i++) { //���� �Է¹��� for��
        cin >> tips[i]; //�� �Է�
    }
    //����
    sort(tips.begin(), tips.end(), greater<>()); //�������� ����
    //���
    cout << calTip(n, tips) << '\n'; //�Լ��� ����� �� �հ� ���
    return 0;
}