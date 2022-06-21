#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//�������� + DP
vector<int> topologicalSort(int n, vector<int>& t, vector<int>& indegree, vector<vector<int>>& graph) {
    queue<int> q; //���������� ���� ��� ����
    vector<int> dp(n + 1, 0); //���� ��ȹ�� ���� �迭

    for (int i = 1; i <= n; i++) {
        dp[i] = t[i]; //���� ��ȹ�� ���� �� �ǹ� �ð� �Է�
        if (!indegree[i]) { //���������� �ִٸ� ť�� �־� ���߿� ���
            q.push(i);
        }
    }
    while (!q.empty()) { //ť�� �ǹ��� �ִٸ�
        int node = q.front(); //�ϳ� ������
        q.pop(); //ť���� ��

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i]; //���� �ǹ��� ���� ���
            dp[next_node] = max(dp[next_node], dp[node] + t[next_node]); //���� ���� �ɸ��� �ð��� ���� ��忡 �ʿ��� �ð�

            indegree[next_node]--; //�������� ���̱�
            if (!indegree[next_node]) { //���� ���������� �ִٸ�
                q.push(next_node); //ť�� �ֱ�
            }
        }
    }
    return dp;
}

/**
 * [���� ����]
 *
 * - ACM Craft (1005) �� ������ ����
 * - �ּ� �ð� = �ǹ��� ���ÿ� ���� �� �ִ� �� �ִ��� ���ÿ� ����� �ּ� �ð��� �ɸ��Ƿ� �� �� ���� �� ���� ���� �ɸ��� �ð��� ����
 */

int main() {
    int n, input; //�ǹ� ���� ��, �Է�

    //�Է�
    cin >> n; //�ǹ� ���� �� �Է�
    vector<int> t(n + 1, 0); //�ǹ��� ���µ� �ɸ��� �ð�
    vector<int> indegree(n + 1, 0); //�������� �迭
    vector<vector<int>> graph(n + 1, vector<int>(0)); //�켱���� �ǹ� �׷���
    for (int i = 1; i <= n; i++) {
        cin >> t[i]; //�ǹ� ���µ� �ɸ��� �ð� �Է�
        while (cin >> input) { //�Է¹ޱ�
            if (input == -1) { //-1�̶�� ��
                break;
            }
            graph[input].push_back(i); //�ǹ� �׷����� �ֱ�
            indegree[i]++; //�������� ī��Ʈ
        }
    }

    //����
    vector<int> ans = topologicalSort(n, t, indegree, graph); //�� �ǹ� �ּ� �ð� ���

    //���
    for (int i = 1; i <= n; i++) { //�� �ǹ� �ð� ���
        cout << ans[i] << '\n';
    }
    return 0;
}