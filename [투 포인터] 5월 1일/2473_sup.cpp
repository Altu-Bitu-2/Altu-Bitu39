#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//�ٸ� ��ġ���� �����Ͽ� ���θ� ���� ��������� �� ������
pair<ll, ll> liquid(vector<ll>& arr, ll fixed, int left, int right) {
    pair<ll, ll> ans; //��ȯ�� ����� pair
    ans = make_pair(INF, INF); //INF������ ����Ʈ ����

    while (left < right) { //�� �����Ͱ� ��ġ�� ���� ������
        ll mix = fixed + arr[left] + arr[right]; //������ + �� ������ ��
        if (mix == 0) { //���� 0�� ���
            return make_pair(arr[left], arr[right]); //�ش� �� ��ȯ
        }
        if (abs(mix) < min_diff) { //���� ������ �ּڰ����� ���� ���
            min_diff = abs(mix); //�ּڰ� �缳��
            ans = make_pair(arr[left], arr[right]); //ans�� �����صα�
        }
        if (mix > 0) { //���� 0���� ũ��
            right--; //right�� �ٿ� 0�� ������
        }
        else { //���� 0���� ������
            left++; //left�� �÷� 0�� ������
        }
    }
    return ans; //ans ��ȯ
}

/**
 * 2470�� : �� ��� ����
 * 2473�� : �� ��� ����
 *
 * [�� ���]
 *
 * 1. �ϳ��� ����� �ݵ�� ����Ѵٰ� ����
 * 2. ��� �ϳ� ����
 * 3. �ش� ��� ������ ������ ���� �� ������ �˰��� ����
 *
 * pair : 2���� �� ����
 * tuple : 3���� �� ����
 *
 * !����! �� ����� �ִ��� 1e9(=10��)�̱� ������ 3���� ���� �ִ��� 30���̰�, int�� �Ѿ!
 */
int main() {
    int n; //��ü ����� ��

    //�Է�
    cin >> n;
    vector<ll> arr(n, 0); //�� ����� Ư���� ����
    for (int i = 0; i < n; i++) { //Ư���� �Է�
        cin >> arr[i];
    }

    //����
    sort(arr.begin(), arr.end()); //Ư���� ����
    tuple<ll, ll, ll> ans; //3��¦ tuple
    for (int i = 0; i < n - 2; i++) { //ó������ n-2���� i ����
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] ����� ����
        if ((p.first != INF) && (p.second != INF)) { //�ּڰ��� ���ŵ� ���
            ans = make_tuple(arr[i], p.first, p.second); //���ο� ������ ��°� ����
        }
    }

    //���
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans); //ans���� get���� ���
    return 0;
}