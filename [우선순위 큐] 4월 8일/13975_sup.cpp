#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

ll getCost(priority_queue<ll, vector<ll>, greater<>>& pq) {
    ll ans = 0;

    while (pq.size() > 1) {
        ll card1 = pq.top(); //���� ���� ��
        pq.pop();
        ll card2 = pq.top(); //�� ��° ���� ��
        pq.pop();
        ans += card1 + card2;
        pq.push(card1 + card2); //���ؼ� �ٽ� ��(�� ���� ����� �� ���� ������ ��ӵǹǷ�)
    }
    return ans;
}

/**
 * [���� ��ġ�� 3]
 *
 * - ������ ���� ��ġ�� ���ؼ��� ������ �ϳ��� ������ �Ѵ�!
 * - �� ��, ������ �������� ���� ���� ���� ����
 * - ����, ���� ���� ���� ���� 2���� ���ľ� ����� �ּ�ȭ �� �� �ִ�.
 * -> �ּ� ������ ����
 *
 * !����! ������ ������ �ִ� 1,000,000 �̰� �� ũ���� �ִ�� 10,000�̹Ƿ�
 *       ������ �ִ��� 10^10���� int ������ �ѱ� ������ long long ��� ��
 */

int main() {
    int t, k, file;

    //�Է�
    cin >> t; //�׽�Ʈ ���̽� ���� �Է�
    while (t--) {
        priority_queue<ll, vector<ll>, greater<>> pq; //�ּ���

        //�Է�
        cin >> k; //�� ���̽� ��� �Է�
        for (int i = 0; i < k; i++) {//�� ���� ���� ũ�� �Է�
            cin >> file;
            pq.push(file);
        }

        //���� & ���
        cout << getCost(pq) << '\n';
    }
    return 0;
}