#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> simulation(int k, queue<int>& q) {
    vector<int> result; //�似Ǫ�� ���� ��ȯ ���� ��� ����
    int cnt = 0; //ī��Ʈ ����

    while (!q.empty()) {
        int x = q.front();
        q.pop(); //���� �� ������ ����
        cnt++; //�� Ƚ���� ī��Ʈ
        if (cnt == k) { //k��° pop�ϴ� ���Ҷ��
            result.push_back(x); //��ȯ ���� ����
            cnt = 0; //k ī��Ʈ �ʱ�ȭ
            continue;
        }
        q.push(x); //pop�� ���� �ٽ� push
    }
    return result;
}

/**
 * 1. ť�� 1 ~ N���� �� �ʱ�ȭ
 * 2. ���� k ��° ��� ã�� ���� pop, push �ݺ�
 * 3. k��° pop �� ��� �似Ǫ�� ������ ����, ���� ���� ���� (�ٽ� push ���� ����!)
 */

int main() {
    int n, k;
    queue<int> q;

    //�Է�
    cin >> n >> k; //n, k �Է�
    for (int i = 1; i <= n; i++) { //ť �ʱ�ȭ
        q.push(i);
    }
    //����
    vector<int> result = simulation(k, q); //�似Ǫ�� ���
    //���
    cout << '<'; //��� ���� ���߱�
    for (int i = 0; i < result.size() - 1; i++) { //�似Ǫ�� ���
        cout << result[i] << ", ";
    }
    cout << result[result.size() - 1] << '>'; //��� ���� ���߱�
    return 0;
}