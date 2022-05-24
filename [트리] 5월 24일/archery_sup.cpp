#include <vector>
#include <iostream>

using namespace std;
const int SIZE = 10;

vector<int> answer = { -1 }; //���̾��� ���� ū ���� ���̷� ����ϴ� ���
int max_diff = 0; //���� ū ���� ����

bool cmp(vector<int>& ryan) {
    for (int i = SIZE; i >= 0; i--) {
        if (answer[i] > ryan[i]) { //���� answer���� �� ���� ȭ���̸�
            return false; //false ��ȯ
        }
        else if (answer[i] < ryan[i]) { //���� answer���� �� ���� ȭ���̸�
            return true; //true ��ȯ
        }
    }
}

int calcDiff(vector<int>& ryan, vector<int>& apeach) {
    int score_r = 0, score_a = 0; //���� ���� �ʱ�ȭ
    for (int i = 0; i <= SIZE; i++) { //���� ���
        int score = SIZE - i; //���� +�� ���� �ʱ�ȭ
        if (ryan[i] > apeach[i]) { //���̾� ȭ���� ���ٸ�
            score_r += score; //���̾� ���� �߰�
        }
        else if (ryan[i] < apeach[i]) { //����ġ ȭ���� ���ٸ�
            score_a += score; //����ġ ���� �߰�
        }
    }
    return score_r - score_a; //���̾� ���� - ����ġ ���� ��ȯ
}

void backtracking(int cnt, int extra_arrows, vector<int>& ryan, vector<int>& apeach) {
    if (cnt == SIZE + 1 || extra_arrows == 0) { //(��������) 0�� ������� Ž�� or ���� ȭ�� ����
        ryan[SIZE] = extra_arrows; //ȭ�� �������� �� �����Ƿ�
        int curr_diff = calcDiff(ryan, apeach); //���� ���� ���
        if (max_diff < curr_diff) { //���� ���� �� ũ�ٸ�
            max_diff = curr_diff; //����
            answer = ryan; //answer ����
        }
        //���� ���� 0�� �ƴ� �ִ����� ���� cmp���� true ��ȯ ��
        else if (curr_diff != 0 && max_diff == curr_diff && cmp(ryan)) {  
            answer = ryan; //answer ����
        }
        return;
    }
    if (extra_arrows > apeach[cnt]) { //���� ȭ��� ���̾��� ������ ���� �� �ִٸ�
        ryan[cnt] = apeach[cnt] + 1; //���̾��� ����ġ���� �ϳ� �� ���� ȭ���� ���
        backtracking(cnt + 1, extra_arrows - apeach[cnt] - 1, ryan, apeach); //���� ��� ���
        ryan[cnt] = 0; //ȭ���� ���� ���� ��� �ʱ�ȭ
    }
    backtracking(cnt + 1, extra_arrows, ryan, apeach); //ī��Ʈ ���ذ��� ��� ��Ʈ��ŷ
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(SIZE + 1, 0); //���̾��� ���� ����
    backtracking(0, n, ryan, info); //����
    return answer; //��� ��ȯ
}

/**
 * [��ô�ȸ]
 *
 * 1. ������ ��� ��츦 ��Ʈ��ŷ Ž���� ���� �˻�
 * -> ���̾��� ������ ������ ����ġ���� 1�� �� ��� ��찡 ����. ����ġ���� ���� ȭ�� ��� �� ���� �� ���Ƿ� ������ �ǹ̰� ����.
 * -> ���� ���̾��� �� ������ ȭ���� �Ʒ��� ���� ��� 2���� ��츸 ����ؼ� ��������� ��� ��츦 ��Ʈ��ŷ���� Ž��
 *    - ����ġ�� ���� ȹ���� �ϴ� ���: �ش� �������� ȭ���� �� �ߵ� ���� �ʴ� ���� �̵�
 *    - ���̾��� ���� ȹ���� �ϴ� ���: �ʿ��� �ּ� ȭ���� ����ϴ� ���� �̵��̹Ƿ� ����ġ���� ��Ȯ�� �� �� �� ��
 *
 * 2. ���� ū ���� ���̰� ������ ���, ���� ������ �� ���� ���� ��츦 ���ǹ����� ���� �ذ�
 * -> �ܼ� Ž���ϴٰ� ���ŵǴ� ������ �ϸ� �ڳ����̽� ����
 * -> ���� 0�� ������� ���� ���ؼ� ���� ���� ������ �� ���� ���� ��� ������ �� �ֵ��� ��
 *
 * !����! 0�� �ε����� 10�� �������� ����
 */

 //������� ���� ���� �ڵ� - ���α׷��ӽ����� ���� X
int main() {
    int n = 5; //5���� �� ���
    vector<int> info = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }; //���� ����
    vector<int> result = solution(n, info); //�ش� ���
    for (int i = 0; i < result.size(); i++) { //��� �� ���
        cout << result[i] << ' ';
    }
    return 0;
}