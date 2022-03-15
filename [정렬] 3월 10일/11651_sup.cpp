#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

bool cmp(const ci& a, const ci& b) {
    if (a.second != b.second) { //1. y좌표가 증가하는 순서
        return a.second < b.second;
    }
    return a.first < b.first; //2. (y좌표가 같으면) x좌표가 증가하는 순서
}

int main() {
    int n, a, b;

    //입력
    cin >> n; //좌표 수 입력
    vector<ci> arr(n, { 0, 0 }); //벡터 초기화
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second; //좌표 입력
    }
    //연산
    sort(arr.begin(), arr.end(), cmp); //cmp 기반 좌표 정렬
    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n'; //정렬한 좌표 출력
    }
    return 0;
}