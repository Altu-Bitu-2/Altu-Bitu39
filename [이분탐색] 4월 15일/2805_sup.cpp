#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int>& tree) {
    ll sum = 0;
    for (int i = 0; i < tree.size(); i++) {
        if (height >= tree[i]) { //절단기 설정 높이보다 나무가 작다면 끝
            return sum;
        }
        sum += (tree[i] - height); //절단기 설정 높이보다 크다면 해당 길이만큼 +
    }
    return sum;
}

int upperSearch(int left, int right, int target, vector<int>& tree) {
    while (left <= right) {
        int mid = (left + right) / 2; //가운데 나무
        ll tree_cnt = cntTree(mid, tree);

        //중간 길이 나무부터 가장 큰 나무까지 계산, 다만
        if (tree_cnt >= target) { //목표 길이보다 많다면 더 적게 조정
            left = mid + 1;
        }
        else { //목표 길이보다 적다면 더 많게 조정
            right = mid - 1;
        }
    }
    return left - 1;
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m; //나무의 수, 필요한 나무의 길이
    vector<int> tree(n, 0);
    for (int i = 0; i < n; i++) { //각 나무의 높이
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end(), greater<>()); //각 나무 길이 정렬

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);
    return 0;
}