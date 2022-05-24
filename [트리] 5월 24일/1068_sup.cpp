#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//�־��� ������ ������ ���� ���� ����� ��
int eraseLeafCnt(int node, int& erase_node) {
    //�θ� ���� ���(Ʈ�� ���� ���)�� ����ٸ�
    if (node == erase_node) { 
        return 0; //�Ʒ� ��尡 ���� ������Ƿ� 0 ���
    }
    //tree�� ����ְų� 1���� �����ϴµ� ���� �����
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1; //root�� �����ϹǷ� 1 ���
    }
    int cnt = 0; //ī��Ʈ �ʱ�ȭ
    for (int i = 0; i < tree[node].size(); i++) { //��͸� ���� ��� �������鼭 ���� ��� �� ++
        cnt += eraseLeafCnt(tree[node][i], erase_node);
    }
    return cnt; //���ݱ��� ����� ���� ��� �� ��ȯ
}

/**
 * [Ʈ��]
 *
 * ���� ���� ��� ������ ���� dfs Ž������ ����� ������ ������ �� �̻� Ž������ �ʰ� 0�� ����
 *
 * !����! ����� ������ �ش� �θ� ����� ������ �ڽ� ��忴�� ���, �ش� ������ ����� �θ� ��尡 ���� ��尡 �ż� ������ 1 �������� ����
 * !����! ��Ʈ ��尡 �׻� 0�� �ƴ��� ����
 */

int main() {
    int n, par, root, erase_node; //��� ����, �� ����� �θ�, �θ� ���� ���, ���� ��� ��ȣ

    //�Է�
    cin >> n; //��� ���� �Է�
    tree.assign(n, vector<int>(0)); //�� ��� �θ� ������
    for (int i = 0; i < n; i++) { //�� ��� �θ� ����
        cin >> par; //�� ��� �θ� �Է�
        if (par == -1) { //�θ� ���� �����
            root = i; //root
            continue; //tree�� ���� �ʰ� �̾
        }
        tree[par].push_back(i); //tree�� �ֱ�
    }
    cin >> erase_node; //���� ��� �Է�

    //���� & ���
    cout << eraseLeafCnt(root, erase_node); //��带 ���� �� ���� ��� ����� ���
    return 0;
}