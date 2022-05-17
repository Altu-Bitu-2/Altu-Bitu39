#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

//���ĺ��� ����Ƚ�� ���� �Լ�
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0); //���ĺ��� ����Ƚ�� ���� ����
    for (int i = 0; i < str.size(); i++) { //�ܾ��� �� ���ĺ� ���鼭 Ȯ��
        result[str[i] - 'A']++; //���� ����� ���߾� A�� ���� ����
    }
    return result; //���ĺ��� ����Ƚ�� ��ȯ
}

/**
 * [����� �ܾ�]
 *
 * �ܾ ���� ������ ����
 * 1. �� ���� �ܾ ���� ������ ���ڷ� �̷����
 * 2. ���� ���ڴ� ���� ������ŭ ����
 *
 * ����� �ܾ��� ����
 * 1. �� �ܾ�� �� ���ڸ� ���ϰų�, ���� ���� ������ ��
 *    -> �� �ܾ�� �ٸ� ������ ������ �� 1��
 * 2. �� �ܾ�� �� ���ڸ� �ٲٸ� ���� ������ ��
 *    -> �� �ܾ�� �ٸ� ������ ������ �� 2��
 *    -> !����! �̶�, �� �ܾ��� ���̰� ���ƾ� �� cf) doll | do
 */

int main() {
    int n, ans = 0; //�ܾ��� ����, ����� ����� �ܾ��� ����
    string source, target; //ù ��° �ܾ�� �ٸ� �ܾ��

    //�Է�
    cin >> n >> source; //�ܾ� ����, ù ��° �ܾ� �Է�

    //����
    vector<int> source_alpha = alphaMap(source); //ù ��° �ܾ� ���ĺ� Ȯ��
    while (--n) { //�ٸ� �ܾ�� ���� �Է�&������ ������
        cin >> target; //�ٸ� �ܾ� �Է�

        int diff = 0; //���̸� Ȯ���� ����
        vector<int> target_alpha = alphaMap(target); //�ٸ� �ܾ� ���ĺ� Ȯ��
        for (int i = 0; i < SIZE; i++) { //�� �ܾ��� ����
            diff += abs(source_alpha[i] - target_alpha[i]); //���̰� �ִ� ��ŭ diff ����
        }
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) { //���ڸ� ���ϰų�, ���ų�, �ٲٰų�
            ans++; //����� �ܾ� �� ����
        }
    }

    //���
    cout << ans; //����� �ܾ� �� ���
    return 0;
}