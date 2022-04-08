#include <iostream>
#include <deque>

using namespace std;

string dqToString(deque<char>& dq) { //Ŀ�� ���� ������ �̾ �ϳ��� ��й�ȣ�� ����
    string ans = "";
    while (!dq.empty()) {
        ans += dq.front();
        dq.pop_front();
    }
    return ans;
}

string findPass(string s) {
    deque<char> dq_left;  //Ŀ�� ���� ������ ����
    deque<char> dq_right; //Ŀ�� ���� ������ ����

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '-': //���� Ŀ�� �տ� �ִ� ���ڸ� �����.
            if (!dq_left.empty()) {
                dq_left.pop_back();
            }
            break;
        case '<': //Ŀ���� �������� �̵� -> dq_left �� ������ ���Ҹ� dq_right �տ� ����
            if (!dq_left.empty()) {
                dq_right.push_front(dq_left.back());
                dq_left.pop_back();
            }
            break;
        case '>': //Ŀ���� ���������� �̵� -> dq_right �� ó�� ���Ҹ� dq_left �� �������� ����
            if (!dq_right.empty()) {
                dq_left.push_back(dq_right.front());
                dq_right.pop_front();
            }
            break;
        default: //������ ���, �Է��� �ϸ� Ŀ������ ���ʿ� ��ġ�ϹǷ� dq_left�� ����
            dq_left.push_back(s[i]);
            break;
        }
    }

    string pass = dqToString(dq_left); //Ŀ�� �պκа� �޺κ� ����
    pass += dqToString(dq_right);
    return pass; //��й�ȣ ��ȯ
}

/**
 * [Ű�ΰ�]
 *
 * �ش� Ǯ�̴�, ���� ���� ���� �� �̵���Ű�� �������� ����� �ڳ����̽��� �ذ��ϱ� ���� Ŀ���� �������� ����, ���������� ������ ���� ������
 *
 * 1. Ŀ�� ���� ���ڸ� ���� ��, ���ڰ� ���� ��� ����
 * 2. Ŀ���� �������� �̵��� ��, �̹� ���� ���ʿ� Ŀ���� �ִ� ��� ����
 * 3. Ŀ���� ���������� �̵��� ��, �̹� ���� �����ʿ� Ŀ���� �ִ� ��� ����
 */

int main() {
    int t;
    string s;

    //�Է�
    cin >> t; //�׽�Ʈ ���̽� ���� �Է�
    while (t--) {
        cin >> s; //�Է��� ���ڿ�

        //���� & ���
        cout << findPass(s) << '\n';
    }
    return 0;
}