#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>& people, vector<int>& init, int n) {
    vector<int> rest(n + 1, 0); //�� ����� ��Ӹ� �ϱ� ���� �ʿ��� �ּ� �ֺ��� ��
    vector<int> ans(n + 1, -1); //�� �� �Ŀ� �ϴ���
    queue<int> q; //bfs ��� ���� ť

    //���� ���� �ʱ�ȭ
    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0; //���� �����ڴ� 0�п� ����
        q.push(init[i]); //bfx ��� ���� ť�� �ֱ�
    }

    //��� �Ͼ�� �ϴ� �ֺ��� �� �ʱ�ȭ
    for (int i = 1; i <= n; i++) { //�� ������� �ּ� �ֺ��� �� ���
        rest[i] = (people[i].size() + 1) / 2;
    }

    while (!q.empty()) {
        int curr = q.front(); //���� ���
        int t = ans[curr]; //��� ���� �ð�
        q.pop(); //����� ����� ť���� ����

        for (int i = 0; i < people[curr].size(); i++) {
            int next = people[curr][i]; //���� ����� ���� ���
            if (ans[next] > -1) { //�̹� ��Ӹ� �ϴ´ٸ�
                continue; //��ŵ
            }
            rest[next]--; //�ּ� �ֺ��� �� �پ��
            if (!rest[next]) { //�ֺ��ε� �� ���� �̻��� ��Ӹ� ������(���� �پ� 0�� �Ǿ��ٸ�)
                ans[next] = t + 1; //���� �ð��� +1
                q.push(next); //���� ����� ���� ����� ����ϱ� ���� ť�� �ֱ�
            }
        }
    }
    return ans;
}

/**
 * [���]
 *
 * �ֺ��ε��� �󸶳� �ϴ����� �迭�� ���� �����ؾ� ��
 * �湮 üũ �迭�� ��Ӹ� �ϴ� �ð��� �����ϴ� �迭�� ��ü��
 *    ans[i] = -1 �� ���, i�� ��Ӹ� ���� �ʴ´�
 *    ans[i] = t�� ���, i�� t�� ���� ��Ӹ� �ϱ� ������
 * ���ڰ� ��Ӹ� �ϱ� ���� �ֺ����� ���� �̻��� ��Ӹ� �Ͼ�� �ϹǷ�, �� ����� ��Ӹ� �ϱ���� ��Ӹ� �ϴ� �ֺ��� ����� ���Ҵ����� ����Ʈ�� ����Ѵ�.
 * ���� ����� 0�� ����, �ش� ����� ��Ӹ� �ϱ� ����
 */

int main() {
    int n, m, input; //����� ��, ���� ������ ��, �ֺ��� �ľ� ���� input

    //��� �۶߸��� ���� �Է�
    cin >> n; //��� �� �Է�
    vector<vector<int>> people(n + 1, vector<int>()); //�ֺ��� ���� ����
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> input; //input �Է�
            if (!input) { //0 �Է� �� �ֺ��� �Է� ����
                break;
            }
            people[i].push_back(input); //i��° ����� �ֺ������� �ֱ�
        }
    }

    //���� ������ �Է�
    cin >> m; //���� ������ �� �Է�
    vector<int> init(m, 0); //���� ������ ����
    for (int i = 0; i < m; i++) { //���� ������ ��ȣ �Է�
        cin >> init[i];
    }

    //����
    vector<int> ans = bfs(people, init, n); //��� ����� ��Ӹ� �ϱ� �����ϴ� �ð� ���

    //���
    for (int i = 1; i <= n; i++) { //�� ������� �ɸ��� �ð� ���
        cout << ans[i] << ' ';
    }
    return 0;
}