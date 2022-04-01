#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;
const int SIZE = 11;

int n;
vector<int> num(SIZE + 1);
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX; //�ִ�, �ּ� ����

void backtracking(int cnt, int sum) { //cnt: �� �ε���, sum: ���� ���
    if (cnt == n - 1) { //���� ��� �Ϸ��ߴٸ� (��������) �ִ�, �ּ� ��ȯ
        max_value = max(max_value, sum); 
        min_value = min(min_value, sum);
        return;
    }
    for (int i = 0; i < 4; i++) { //������ �˻�
        if (expression[i]) {
            expression[i]--; //ī��Ʈ--
            int new_sum = 0;
            switch (i) { //������ ������ ����
            case 0: //����
                new_sum = sum + num[cnt + 1];
                break;
            case 1: //����
                new_sum = sum - num[cnt + 1];
                break;
            case 2: //����
                new_sum = sum * num[cnt + 1];
                break;
            case 3: //������
                new_sum = sum / num[cnt + 1];
                break;
            }
            backtracking(cnt + 1, new_sum); //������ �Ϸ��� ������ ��͸� ���� ���
            expression[i]++; //���� ����� ���� ��Ͱ� ���� �� ī��Ʈ ��������
        }
    }
}

/**
 * ������ ��� �������鼭 ��ġ�� ��, �� �����ڿ� ���� �� ���
 */

int main() {
    //�Է�
    cin >> n; //���� ����
    for (int i = 0; i < n; i++) { //�� �Է�
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) { //+-*/ ����
        cin >> expression[i];
    }

    //����
    backtracking(0, num[0]);

    //���
    cout << max_value << '\n' << min_value; //�ִ�, �ּڰ� ���
    return 0;
}