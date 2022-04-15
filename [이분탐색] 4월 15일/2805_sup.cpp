#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int>& tree) {
    ll sum = 0;
    for (int i = 0; i < tree.size(); i++) {
        if (height >= tree[i]) { //���ܱ� ���� ���̺��� ������ �۴ٸ� ��
            return sum;
        }
        sum += (tree[i] - height); //���ܱ� ���� ���̺��� ũ�ٸ� �ش� ���̸�ŭ +
    }
    return sum;
}

int upperSearch(int left, int right, int target, vector<int>& tree) {
    while (left <= right) {
        int mid = (left + right) / 2; //��� ����
        ll tree_cnt = cntTree(mid, tree);

        //�߰� ���� �������� ���� ū �������� ���, �ٸ�
        if (tree_cnt >= target) { //��ǥ ���̺��� ���ٸ� �� ���� ����
            left = mid + 1;
        }
        else { //��ǥ ���̺��� ���ٸ� �� ���� ����
            right = mid - 1;
        }
    }
    return left - 1;
}

/**
 * [���� �ڸ���]
 *
 * ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ���?
 * -> ���ܱ��� ���̰� k(������ ��)�� ��, M������ ������ ���� ������ �� �ִ°�?
 *
 * left: ���ܱ��� �ּ� ���� -> 0
 * right: ���ܱ��� �ִ� ���� -> �־��� ���� �� ���� ���� ���� ����
 *
 * !����! int �ڷ��� ������ �Ѿ�Ƿ� long long��� ��
 */

int main() {
    int n, m;

    //�Է�
    cin >> n >> m; //������ ��, �ʿ��� ������ ����
    vector<int> tree(n, 0);
    for (int i = 0; i < n; i++) { //�� ������ ����
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end(), greater<>()); //�� ���� ���� ����

    //���� & ���
    cout << upperSearch(0, tree[0], m, tree);
    return 0;
}