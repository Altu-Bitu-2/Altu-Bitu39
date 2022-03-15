#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

bool cmp(const ci& a, const ci& b) {
    if (a.second != b.second) { //1. y��ǥ�� �����ϴ� ����
        return a.second < b.second;
    }
    return a.first < b.first; //2. (y��ǥ�� ������) x��ǥ�� �����ϴ� ����
}

int main() {
    int n, a, b;

    //�Է�
    cin >> n; //��ǥ �� �Է�
    vector<ci> arr(n, { 0, 0 }); //���� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second; //��ǥ �Է�
    }
    //����
    sort(arr.begin(), arr.end(), cmp); //cmp ��� ��ǥ ����
    //���
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n'; //������ ��ǥ ���
    }
    return 0;
}