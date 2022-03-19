#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 26;    // ���ĺ��� ��

vector<int> countAlphabet(string text) {
    // text�� �ִ� �� ���ĺ��� ������ ���� �����ϴ� �Լ�
    vector<int> count(SIZE, 0); // A-Z���� ������ ������ ������ ����Ʈ
    for (int i = 0; i < text.size(); i++) {
        // �� ���ڸ� �ε����� �ٲ��ֱ� ���� 'A'�� �ε����� ����(�ƽ�Ű�ڵ�)
        count[text[i] - 'A']++; //ī��Ʈ
    }
    return count; //��ȯ
}

string makePalindrome(vector<int>& count) {
    // �Ӹ������ ����� �����ϴ� �Լ�.
    string part1 = "", part2 = "", part3 = ""; //

    for (int i = 0; i < SIZE; i++) {
        // ���� ���ĺ��� ���� Ȧ�����
        if (count[i] % 2 == 1) {
            // �̹� ��� ���ڰ� á�ٸ� �� �̻� �Ұ���
            if (part2.size() == 1) {
                return "I'm Sorry Hansoo";
            }
            // ��� ���ڰ� ����ִٸ� �Ҵ�
            part2 = (char)(i + 'A');
        }
        // ���� ���� ������ ������ part1�� part3�� �̾� ���δ�
        for (int j = 0; j < count[i] / 2; j++) {
            part1 += (char)(i + 'A');
            part3 = (char)(i + 'A') + part3;
        }
        /*
        i + 'A'�� �ε������� �ٽ� ���ĺ����� �ٲپ� ����ϱ� ����

        ���� ������ ������ ����Ʈ�� ������� ���캽
        ������ Ȧ����� ��������� �Ҵ�
        ¦����� ������ ������ ���� part1, ������ part3
        ��, �������� ��Ī�̾�� �ϹǷ� part3�� ���ؾ� ��
        */

    }

    return part1 + part2 + part3; //��ȯ
}

/*
 * [�Ӹ���� �����] - �ܼ� ���� ����
 * �Ӹ���� ���ڿ��� part1(part3�� ��Ī) + part2(�ִ� 1����) + part3(part1�� ��Ī)���� �̷������.
 * 1. �Ӹ���� ���ڿ��� ����� ����, �� ���ĺ��� �� ���� �����ϴ��� ���Ϳ� �����Ѵ�.
 * 2. ���������� �ռ� �Ӹ���� ���� ������ �ϹǷ�, 'A'���� �����ؼ� part1�� part3�� ������ ������ ���� ���س�����.
 * 3. ���� ���ĺ��� ������ Ȧ���� ���, part2�� �Ҵ��ϰ�, �̹� part2�� ���ڰ� �ִ� ��쿣 �Ӹ������ ���� �� ����.
 */


int main() {
    // �Է�
    string input; //string ����
    cin >> input; //string �Է¹���

    // ���� + ���
    vector<int> count = countAlphabet(input); //�� ���ĺ� ���� ī����
    cout << makePalindrome(count); //�Ӹ���� ������ ���

    return 0;
}