#include <iostream>
#include <vector>

using namespace std;

int findRanking(int n, int new_score, int p, vector<int>& ranking) {
    int idx = 1;
    int ans = 1;
    //���ο� ������ ��� ��ġ�� ������ Ž��
    while (idx <= n) {
        if (new_score > ranking[idx]) { //���ο� ������ �� ũ�ٸ� �ش� ��ġ��
            break;
        }
        if (new_score < ranking[idx]) { //���ο� �������� �۴ٸ� ���� �ε�����
            ans = idx + 1;
        }
        idx++; //�ε��� ++
    }
    if (idx == p + 1) { //��ŷ ����Ʈ�� ���� ���ϴ� ���
        return -1;
    }
    return ans; //�ε���(��ŷ) ��ȯ
}

/**
 * [��� ���ϱ�]
 *
 * 1. n = 0�� ��, ���
 * 2. ����� p���� ������, ������ �� ���� ���� ��ŷ�� ���ŵǹǷ� ��ŷ ����Ʈ�� ���� ���ϴ� ��� ��� (����)
 *
 * ���� ��ŷ�� �ö� n���� ����� ���ο� ������ ���ϸ� ���ο� ���� �� ������ ���
 * ���ο� ������ ���� Ž�� ����� �������� �۴ٸ� -> ���� Ž�� ��� + 1
 * ������ ��� -> �� �� ��� �״�� ��� -> �ƹ� ó���� ���� ����!
 */

int main() {
    int n, new_score, p;

    //�Է�
    cin >> n >> new_score >> p; //���� ����, ���ο� ����, ��ŷ����Ʈ ǥ�� ���� ���� �Է�
    vector<int> ranking(p + 1, 0); //��ŷ����Ʈ
    for (int i = 1; i <= n; i++) { //�� ��ŷ����Ʈ ���� �Է�
        cin >> ranking[i];
    }

    //���� & ���
    cout << findRanking(n, new_score, p, ranking); //���ο� ������ ��ŷ
    return 0;
}