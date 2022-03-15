//
// Created by JIYOUNG.P on 2022-03-07.
//

#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * ver1. set�� �̿��� Ǯ���Դϴ�.
 * ������ �� �ʿ䰡 ����, ���԰� �˻��� �Ͼ�� �����Դϴ�.
 * �Է��� ���� �ִ� 1,000,000���� ���԰� Ž���� ���� �Ͼ�ϴ�.
 * ����, O(log N)�� set�� �ƴ϶� O(1)�� unordered_set�� ����ؼ� Ǯ��� �մϴ�.
 * */

int main() {
    // ����� ó�� �ӵ� ����� ���� �ڵ�
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // �Է�
    int t; //�׽�Ʈ���̽� ����
    cin >> t; //�׽�Ʈ���̽� ���� �Է�
    while (t--) { //���̽� ������ ��� while��
        int n, m, input; //���� ����, �Է� ���� ��
        unordered_set<int> note1; //��ø1 set

        // ��ø1�� �ش�Ǵ� ���ҵ��� unordered_set�� ����
        cin >> n; //��ø1 ���� ���� �Է�
        while (n--) { //��ø1 �� ���� �Է� while��
            cin >> input; //input�� ���� �Է�
            note1.insert(input); //input�� set�� ����
        }
        cin >> m; //��ø2 ���� ���� �Է�
        while (m--) { //��ø2 �� ���� �Է�&�Ǻ� while��
            cin >> input; //input(��ø2 ����) �Է�
            // �ݺ��ڸ� �̿��ؼ� ���Ұ� �¿� ���ԵǾ� �ִ��� Ȯ��
            auto iter = note1.find(input); //find Ȱ�� �ݺ��� ����
            if (iter == note1.end()) { //end Ȱ��, ���� ���
                cout << "0\n";
            }
            else { //���� ���
                cout << "1\n";
            }
        }
    }
    return 0;
}