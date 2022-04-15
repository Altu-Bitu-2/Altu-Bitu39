#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

//Ư�� ȭ��ǥ���� ������ ����� ���� ����
string arrowStartWheel(int arrow_point, int n, vector<char>& wheel) {
    string ans = "";
    int start = arrow_point; //������ ȸ�� ȭ��ǥ
    do {
        ans += wheel[arrow_point]; //����� ������ �ϳ��� �־���
        arrow_point = (arrow_point + 1) % n; //���� ����� ����
    } while (arrow_point != start); //�ѹ��� ���� ������
    return ans;
}

//����� ���� ���ϴ� �Լ�
string makeWheel(int n, vector<ci>& record) {
    vector<char> wheel(n, '?'); //������ ����
    vector<bool> is_available(26, false); //���ĺ� �ߺ� üũ

    int idx = 0; //ȭ��ǥ�� ����Ű�� �ε���
    for (int i = 0; i < record.size(); i++) { 
        int rot = record[i].first;
        char alpha = record[i].second;
        idx = (idx - rot % n + n) % n; //�� ���� �̻��� ������ �� �ε��� üũ�� ����
        if (wheel[idx] == alpha) { //�ε����� ���ٸ� ����
            continue;
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) { //����� ������ �߸��� ���
            return "!";
        }
        wheel[idx] = alpha; //ȭ��ǥ �ε��� ǥ��
        is_available[alpha - 'A'] = true; //�̹� Ȯ�ε� ���ĺ����� ǥ��
    }
    return arrowStartWheel(idx, n, wheel);
}

/**
 * [����� ����]
 *
 * ������ ���ư� �ʿ� X
 * ȭ��ǥ�� ����Ű�� �ε����� ȸ�� ������ ���� �ٲ���
 *
 * 1. ȭ��ǥ�� ����Ű�� ĭ�� �������� �ʾ����� ���ĺ��� ������ ���´�.
 * 2. �̹� ���ĺ��� �� �ִ� ���, ���� ���ĺ��� �ƴ� ��� ���ǿ� �ش��ϴ� ���� ���� �� ����.
 * 3. ������ �����ִ� ���ĺ��� �ߺ����� �����Ƿ� ������ ���ĺ��� ���� �ڸ��� ���� �� ����.
 */

int main() {
    int n, k;

    //�Է�
    cin >> n >> k; //���� ĭ��, ���� ������ Ƚ��
    vector<ci> record(k, { 0, 0 }); //���� ȸ�� ���
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second;
    }

    //���� & ���
    cout << makeWheel(n, record);
    return 0;
}