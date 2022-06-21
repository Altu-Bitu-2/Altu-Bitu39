#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//��������
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {
    priority_queue<int, vector<int>, greater<>> pq; //�ּ���
    vector<int> result; //��ȯ�� �迭

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { //�������� �ִٸ�
            pq.push(i); //���� �ֱ�
        }
    }
    while (!pq.empty()) {
        int node = pq.top(); //������ �ϳ� ��������
        pq.pop(); //����

        result.push_back(node); //���� Ǯ��� �� ����
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i]; //���� ���
            indegree[next_node]--; //�������� ���ֱ�
            if (!indegree[next_node]) { //�������� �ִٸ�
                pq.push(next_node); //���� �־� ����� �� �ֵ���
            }
        }
    }
    return result; //���� ���� ��ȯ
}

/**
 * [������]
 *
 * - ���� 1, 2������ ����� ��������
 * - ���� 3 "�����ϸ� ���� �������� Ǯ��� �Ѵ�." -> �������� ��, ������ ���� ��������
 * - ���� 3�� ������Ű�� ����, ���������� 0�� ������ ��� �����̳ʷ� �켱���� ť ���
 */

int main() {
    int n, m, a, b; //���� ��, ���� Ǫ�� ���� ���� ������ ���� ���� ����, ���� ������ a, b

    //�Է�
    cin >> n >> m; //���� ��, ���� �� �Է�
    vector<int> indegree(n + 1, 0); //�������� ����
    vector<vector<int>> graph(n + 1, vector<int>(0)); //�������� �׷���
    while (m--) {
        cin >> a >> b; //���� ������ �Է�
        graph[a].push_back(b); //a->b
        indegree[b]++; //b�� �������� ++
    }

    //����
    vector<int> result = topologicalSort(n, indegree, graph); //�������� ���

    //���
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' '; //���� ���� ���
    }
    return 0;
}