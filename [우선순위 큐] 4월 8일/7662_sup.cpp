#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<bool> is_valid;

//�ִ� ������ top �����Ͱ� is_valid �� ������ pop
void deleteMax(priority_queue<ci>& heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) {
        heap.pop();
    }
}

//�ּ� ������ top �����Ͱ� is_valid �� ������ pop
void deleteMin(priority_queue<ci, vector<ci>, greater<>>& heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) {
        heap.pop();
    }
}

/**
 * �켱���� ť Ǯ��
 * �ִ� ���� �ּ� ���� ���ÿ� �����ϸ鼭 ������ ������ ������ �����͸� �ٸ� ���� �ݿ��ϴ� ���
 * -> �� �������� ��ȿ���� üũ�ϴ� �迭�� �����
 */
int main() {
    int t, k, n;
    char cmd;

    cin >> t; //�׽�Ʈ ������ ���� �Է�
    while (t--) {
        priority_queue<ci> max_heap; //�ִ� ��
        priority_queue<ci, vector<ci>, greater<>> min_heap; //�ּ� ��
        cin >> k; //�� ���̽� ���� ���� �Է�
        int idx = 0; //I �������� �Էµ� ������ �ε���
        while (k--) {
            //�Է�
            cin >> cmd >> n; //���� �Է�

            //����
            switch (cmd) {
            case 'I': //�ΰ��� �� ��ο� ���� ���� ��, is_valid ���Ϳ��� �߰�
                max_heap.push(ci(n, idx));
                min_heap.push(ci(n, idx));
                is_valid.push_back(true);
                idx++;
                break;
            case 'D': //n�� ���� �ִ� �� �Ǵ� �ּ� ������ ������ ����
                if (n == 1) { //�ִ� ���� ����
                    deleteMax(max_heap); //D���� ��ó��
                    if (!max_heap.empty()) { //D����
                        is_valid[max_heap.top().second] = false;
                        max_heap.pop();
                    }
                }
                if (n == -1) { //�ּڰ� ���� ����
                    deleteMin(min_heap); //D���� ��ó��
                    if (!min_heap.empty()) { //D����
                        is_valid[min_heap.top().second] = false;
                        min_heap.pop();
                    }
                }
                break;
            }
        }
        //���������� �� ���� top�� valid �ϵ��� ó��
        deleteMax(max_heap);
        deleteMin(min_heap);

        //���
        if (max_heap.empty()) { //Q�� �� ���
            cout << "EMPTY\n";
        }
        else { //�ִ�, �ּ� ���
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';
        }
        is_valid.clear(); //���ο� �׽�Ʈ ���̽� �� is_valid ���� �ʱ�ȭ
    }
}