#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * �� �ٸ��� �ܰ����� ������ �ִ� ������ ���ÿ� �����ϱ�
 * �� �Է¿� ���� �̹��� ���� ������ �ش� �ٿ��� ���� ���� �����̾�� ��
 *
 * 1. �̹��� ������ �� �������� ���� �������� �հ����� ���� ����
 * 2. ���� �̹��� ������ �� ������ ������ ���� �ʴٸ� ������
 *
 * �������� �ʴ� 0�� ������ Ȱ���ؼ� ���ÿ� �̸� �־������ν� �Ź� empty üũ�� �ؾ� �ϴ� ������ ����
 */
int main() {
    int n, p, guitar_string, fret, ans = 0;

    cin >> n >> p; //���� ��, ���� �� �Է�
    vector<stack<int>> guitar(7); //1�� �ٺ��� 6���� ����
    for (int i = 1; i <= 6; i++) { //���ÿ� �̸� 0�� �־ �Ź� empty üũ�� �ϴ� ������ ����
        guitar[i].push(0);
    }
    while (n--) {
        //�Է�
        cin >> guitar_string >> fret; //���� �� �Է�

        //����
        while (guitar[guitar_string].top() > fret) { //���� ���� �� �� ������ ���� �������� ������ ���
            ans++; //Ƚ�� ī��Ʈ
            guitar[guitar_string].pop(); //�������� �հ��� ����
        }
        if (guitar[guitar_string].top() != fret) { //���� ���� �� �� ������ ���� �������� �Ʒ��� ���
            ans++; //Ƚ�� ī��Ʈ
            guitar[guitar_string].push(fret); //���� ������
        }
    }

    //���
    cout << ans;

    return 0;
}