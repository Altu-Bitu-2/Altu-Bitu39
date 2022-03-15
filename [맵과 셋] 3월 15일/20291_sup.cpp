#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * �ߺ����� ������ �ʿ��� ���
 * key(Ȯ����)-value(���� ����) ���� �ʿ��ϹǷ� map ���
 */

int main() {
    int n; //���� ����
    string input; //���� �̸�
    map<string, int> extension; //key: Ȯ����, value: Ȯ���� ���� ����

    //�Է� & ����
    cin >> n; //���� ���� �Է�
    while (n--) {
        cin >> input; //���� �̸� �Է�
        //string.substr(pos, len): ù ��° ������ ��ġ(pos)���� pos + len ������ �κ� ���ڿ�
        //pos + len �� ���ڿ����� ��ٸ� ���ڿ� ������ ���ڱ����� �����ϵ��� ó��
        string ext = input.substr(input.find('.') + 1, input.length()); //.���� �κ� ���ڿ� ����
        //������ ���ڿ� = ����('.'���� ������ ����)
        extension[ext]++; //������ ���ڿ� key�� Ȯ���� ���� �߰�
    }
    //���
    for (auto iter = extension.begin(); iter != extension.end(); iter++) { //Ȯ����key�� ���� �ݺ��� ����
        cout << iter->first << ' ' << iter->second << '\n'; //Ȯ����+���� ���
    }
    return 0;
}