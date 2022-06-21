#include <iostream>
#include <vector>

using namespace std;

//���л��� ����ġ �ٲٱ�
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {
    for (int i = number; i <= n; i += number) { //����� �ִ� ����ġ �ٲٱ�
        switches[i] = !switches[i];
    }
    return switches; //�ٲ� ����ġ ���� ��ȯ
}

//���л��� ����ġ �ٲٱ�
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {
    switches[number] = !switches[number]; //���� ��ȣ�� ����ġ �ٲٱ�
    for (int i = 1; i < number; i++) {
        if ((number + i > n) || (switches[number - i] != switches[number + i])) { //����ġ ���� �Ѿ�ų� �¿� ��Ī�� �ƴϸ�
            break; //����ġ �ٲٱ⸦ �׸��α�
        }
        switches[number - i] = !switches[number - i]; //������ �����ϴ� ��� ���� ����ġ �ٲٱ�
        switches[number + i] = !switches[number + i]; //������ ����ġ�� �ٲ��ش�
    }
    return switches; //�ٲ� ����ġ ���� ��ȯ
}

/**
 * [����ġ �Ѱ� ����]
 *
 * ���л� -> �ش� ��ȣ�� ����� �ش��ϴ� ����ġ ���� �ٲٱ�
 * ���л� -> �ش� ��ȣ�� �߽����� �¿� ��Ī�̸鼭 ���� ���� ����ġ �����ϴ� ������ ���� ��� �ٲٱ�
 *
 * �¿� ��Ī �˻� ��, ����ġ ���� ���� (�־��� ����ġ ���� �Ѿ�� �ʵ���)
 * ����ġ 20���� ����ϴ� �κ� ����
 */
int main() {
    int n, m; //����ġ ����, �л� ��
    int student, number; //�л� ����, �л��� ���� ��

    //�Է�
    cin >> n; //����ġ ���� �Է�
    vector<int> switches(n + 1, 0); //����ġ ���� ����
    for (int i = 1; i <= n; i++) {
        cin >> switches[i]; //����ġ ���� �Է�
    }

    //�Է� & ����
    cin >> m; //�л� �� 
    while (m--) {
        cin >> student >> number; //�л� ����, ���� �� �Է�
        if (student == 1) { //���л��� ���
            switches = changeSwitchBoy(n, number, switches); //����� ����ġ ���� ����
        }
        else { //���л��� ���
            switches = changeSwitchGirl(n, number, switches); //����� ����ġ ���� ����
        }
    }

    //���
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' '; //����ġ ���� ���
        if (i % 20 == 0) { //20���� ����� �� �ֵ���
            cout << '\n';
        }
    }
    return 0;
}