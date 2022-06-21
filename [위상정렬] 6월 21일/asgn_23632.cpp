#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

//��������
vector<int> topologicalSort(int t, int n, vector<int>& indegree, matrix& resources, matrix& graph) {
    queue<pair<int, int>> q; //first:���������� 0�� �ǹ�, second:�ð�
    vector<bool> check(n + 1, false); //���� �ڿ� üũ �迭
    vector<int> result; //��ȯ�� ������ �ǹ�

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { //���������� �ִٸ�
            q.push({ i, 0 }); //ť�� �ֱ�, �ɸ��� �ð��� 0���� �ʱ�ȭ
        }
    }
    while (!q.empty()) { //ť�� �ǹ��� �ִٸ�
        int x = q.front().first; //ť���� ��������
        int curr_t = q.front().second; //�ð� �ʰ� ����� ����
        q.pop(); //ť���� ��

        if (curr_t > t) { //�ð� �ʰ� ��
            break; //���� �ݺ�
        }
        result.push_back(x); //������ �ǹ��� �߰�
        for (int i = 0; i < resources[x].size(); i++) {
            int resource = resources[x][i]; //�����ϴ� �ڿ�
            if (check[resource]) { //üũ�ߴٸ�
                continue; //���� �ݺ�����
            }
            check[resource] = true;
            for (int j = 0; j < graph[resource].size(); j++) {
                int building = graph[resource][j]; //�ʿ�� �ϴ� �ڿ�
                indegree[building]--; //�������� ���̱�
                if (!indegree[building]) { //�������� ���� �����ִٸ�
                    q.push({ building, curr_t + 1 }); //�ð� +1�� ť�� �ֱ�
                }
            }
        }
    }
    return result; //�ϼ��� ���� �ǹ� ��ȯ
}

/**
 * [��Ű�� ŷ��]
 *
 * �ǹ����� �ʿ�� �ϴ� �ڿ��� ���踦 �׷����� ǥ���Ͽ� ���������� ����� ���� �ð�(t) �̳��� ���� �� �ִ� �ǹ����� ����
 * - �׷��� ����: �ʿ�� �ϴ� �ڿ� -> �ǹ�
 * - �̶�, �� �ǹ����� �����ϴ� �ڿ��� ���� ���̹Ƿ� �������Ŀ��� ����� ������ ���������� �����ϴ� �κп��� �����ϴ� �ڿ��� ��� �˻��ؾ� ��
 * - �� �������� ���� �ٸ� �ǹ����� �����ϴ� �ڿ��� ��ĥ �� �����Ƿ�, �̹� ������ �ڿ��� üũ�� ����
 * - ���������ϴ� ���� �ð��� ������ ����
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t, cnt, resource, building; //�ڿ� ������, �̹� ������ �ǹ� ��, ���� �ð�, �ڿ� ������, �ڿ��� �ǹ� �Է�

    //�Է�
    cin >> n >> m >> t; //�ڿ� ������, ������ �ǹ� ��, ���ѽð� �Է�
    vector<int> indegree(n + 1, 0); //�������� �迭
    matrix graph(n + 1, vector<int>(0)); //�ڿ� �׷���
    matrix resources(n + 1, vector<int>(0)); //�� �ǹ��� �����ϴ� �ڿ���
    for (int i = 0; i < m; i++) { //�̹� ������ �ǹ�
        cin >> building;
    }
    for (int i = 1; i <= n; i++) { //�ǹ��� �����ϴ� �ڿ�
        cin >> cnt; //���� ������ �ڿ� ������
        while (cnt--) {
            cin >> resource; //�ڿ� ��ȣ
            resources[i].push_back(resource); //�ڿ� �迭�� �ֱ�
        }
    }
    for (int i = 0; i < n - m; i++) { //�ǹ����� �ʿ��� �ڿ�
        cin >> building >> cnt; //���� �������� ���� �ǹ� ��ȣ, �ʿ�� �ϴ� �ڿ� ������ �Է�
        indegree[building] = cnt; //�ʿ�� �ϴ� �ڿ� �������� ���������� �Է�
        while (cnt--) {
            cin >> resource; //�ڿ� ��ȣ �Է�
            graph[resource].push_back(building); //�׷����� �ֱ�
        }
    }

    //����
    vector<int> result = topologicalSort(t, n, indegree, resources, graph); //���� �ð� ���� ���� �� �ִ� �ǹ� ���� ���
    sort(result.begin(), result.end()); //�������� ����

    //���
    cout << result.size() << '\n'; //������ �ǹ� ���� ���
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' '; //������ �ǹ� ��ȣ ���
    }
    return 0;
}