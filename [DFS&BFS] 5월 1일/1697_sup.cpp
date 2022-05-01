#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;

int bfs(int n, int k) {
    vector<int> check(SIZE + 1, 0); //üũ�� ��ǥ���� Ȯ���ϱ� ���� ����
    queue<int> q; //ť�� ��ǥ�� ����
    int ans = 0; //����� �� �ʱ�ȭ

    check[n] = 1; //���� ��� �湮üũ + �ð� �ʱ�ȭ
    q.push(n); //ť�� ���� ��ǥ�� ����
    while (!q.empty()) { //ť�� ���� ������ ������
        int x = q.front(); //ť�� �� �� ��ǥ x�� �ʱ�ȭ�� ��
        q.pop(); //ť���� ����

        if (x == k) { //�ش� ��ǥ�� ������ ��ġ���
            ans = check[x] - 1; //����� ��ǥ ���� ��
            break; //��� ������
        }

        vector<int> child = { x - 1, x + 1, x * 2 }; //�ڽ� ���
        for (int i = 0; i < 3; i++) { //�� �ڽ� ��� üũ
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { //��尡 ��ǥ ���� �ְ�, ���� üũ���� ���� ���
                check[child[i]] = check[x] + 1; //�ش� ��ǥ���� �ð� ����
                q.push(child[i]); //ť�� ��ǥ ����
            }
        }
    }
    return ans; //��� ���� �� ��ȯ
}

/**
 * [���ٲ���]
 *
 * x��ǥ ������ x-1, x+1, 2*x�� ��ġ�� ��� �̵��ϸ� Ž��
 * ���� ���� �ð��� ã�ƾ� �ϹǷ� �ֺ� ������ Ž���ϴ� Ǯ�̷� Ǯ� k�� �����ϸ� �ٷ� Ž�� ���� (bfs)
 */

int main() {
    int n, k; //�������� ��ġ, ������ ��ġ

    //�Է�
    cin >> n >> k; //�� ��ġ �Է�

    //���� & ���
    cout << bfs(n, k); //���� ���� �ð� ����� ���
    return 0;
}