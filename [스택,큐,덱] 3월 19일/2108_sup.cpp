#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 4000; //����� �ִ�

int findMode(vector<int>& frequency) {
    int max_value = 0;  //�ֺ��� �󵵼�
    for (int i = 0; i <= SIZE * 2; i++) { //�ֺ��� �󵵼� ���ϱ�
        if (frequency[i] > max_value)
            max_value = frequency[i];
    }
    //�� ��°�� ���� �ֺ� ���ϱ�
    int cnt = 0;  //�ֺ� ����
    int mode = 0; //�ֺ�
    for (int i = 0; i <= SIZE * 2; i++) {
        if (frequency[i] == max_value) {
            mode = i - SIZE; //SIZE�� ���� ������ �ε����� �����߾����Ƿ� ���� ���� SIZE�� ���־�� ��
            cnt++;
            if (cnt == 2) //�� ��°�� ���� �ֺ�
                break;
        }
    }

    return mode;
}

/**
 * [�����]
 * 1. ��� ��� ��� �� �Ǽ� �ڷ��� ���, �ݿø��� ����
 * 2. n�� Ȧ�� �̹Ƿ� �߾Ӱ��� �׻� (n/2)��° �ε���
 * 3. �ֺ��� ������ �󵵼� ������ �� ��°�� '����' ��
 * 4. �ֺ��� ������ ��� ���
 */

int main() {
    int n; //n�� Ȧ��

    //�Է�
    cin >> n; //�Է��� ���� ���� �Է�

    vector<int> num(n); //�� �Է��� ����
    vector<int> frequency(SIZE * 2 + 1, 0); //�ε����� �Է� �� + 4000�� ��. ���� 0 ~ 8000. �� �ε����� �ش� ���� �󸶳� ���Դ��� ����

    int sum = 0; //��� ���ϱ� ���� �� ����
    for (int i = 0; i < n; i++) {
        cin >> num[i]; //�� �Է�
        sum += num[i]; //��� ���ϱ� ���� �հ�
        frequency[num[i] + SIZE]++; //�󵵼� ���ϱ� ���� �� ���ں� ���� ī��Ʈ
    }

    //����
    sort(num.begin(), num.end()); //����

    //���
    //������
    if (round((double)sum / n) == -0) //round �ݿø�
        cout << "0\n"; //0�� ���
    else
        cout << round((double)sum / n) << '\n'; //���� ������ ���
    cout << num[n / 2] << '\n';               //�߾Ӱ�
    cout << findMode(frequency) << '\n';      //�ֺ�
    cout << num[n - 1] - num[0] << '\n';      //����

    return 0;
}