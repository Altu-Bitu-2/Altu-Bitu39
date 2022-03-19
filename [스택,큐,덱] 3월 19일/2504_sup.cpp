#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s) {
    stack<char> st; //��ȣ �� Ȯ���� ����
    map<char, int> num; //��ȣ ��
    map<char, char> bracket; //��ȣ ��

    //��ȣ �ְ� �� ����
    bracket[')'] = '('; // () ��ȣ��
    bracket[']'] = '['; // [] ��ȣ��
    num['('] = 2; // () ��ȣ��
    num['['] = 3; // [] ��ȣ��

    int ans = 0, temp = 1;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '(': case '[': //���� ��ȣ�� ���
            st.push(s[i]); //���ÿ� ����
            temp *= num[s[i]];
            break;
        case ')': case ']': //�ݴ� ��ȣ�� ���
            if (st.empty() || st.top() != bracket[s[i]]) { //������ ��ų� ¦�� �� �´� ���
                return 0; //0 ����
            }
            if (s[i - 1] == bracket[s[i]]) { //¦�� �´� ���
                ans += temp;
            }
            temp /= num[bracket[s[i]]]; //�̹� ���� ���� ����̹Ƿ� ������
            st.pop(); //�۾� �Ϸ� �� ���ÿ��� ������
            break;
        }
    }
    if (st.empty()) { //(���������� ���� �� ������ ��� �ִ�)�ùٸ� ��ȣ���
        return ans; //����� �� ���� ��ȯ
    }
    return 0;
}

/**
 * "�й��Ģ"�� Ȱ��!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   �ӽú�����:  2   6 2     4  12   4   2   1
 * =>                        ����:        +6           +12        = 18
 *
 * ����, �켱 ���� ��ȣ�� ������ ��ȣ�� ���� ������
 * �ݴ� ��ȣ��, ���� ���ڰ� ���� ��ȣ�� ��� ���ݱ��� ���� ���� ������ (���� �ߺ����� �������� ���� �����ϱ� ���� ���� ���ڰ� ���� ��ȣ���� �� üũ!)
 *            �� ��ȣ�� ���� ������ �������Ƿ� (���ϱ� ����) �ٽ� ��ȣ ���� �����༭ ���� ����
 */

int main() {
    string s; //��ȣ ���� string

    //�Է�
    cin >> s; //string �Է�
    //���� & ���
    cout << calc(s); //��� ���� ���
    return 0;
}