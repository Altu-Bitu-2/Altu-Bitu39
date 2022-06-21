#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tieNumber(vector<int>& arr) {
    int total = 0; //총합 초기화
    int size = arr.size(); //개수
    for (int i = 0; i < size - 1; i += 2) { //절댓값 큰 수부터 곱해 더해줌
        total += arr[i] * arr[i + 1];
    }
    //하나 남은 수 더해줌
    if (size % 2) {
        total += arr[size - 1];
    }
    return total; //총합 반환
}

/**
 * [수 묶기]
 *
 * 1. 양수는 양수끼리, 음수는 음수끼리 곱해야 큰 수를 만들 수 있다.
 * 2. 절댓값이 큰 것끼리 곱해야 더 큰 수를 만들 수 있다.
 *     ex) 1, 2, 3, 4 => 4 * 1 + 3 * 2 = 10
 *                    => 4 * 3 + 2 * 1 = 14
 * 3. 1은 곱하는 것보다 더해야 큰 수를 만들 수 있다. (x * 1 = x < x + 1)
 */
int main() {
    int n, x, cnt1 = 0; //수열의 크기, 수열의 각 수, 1 카운트 초기화

    //입력
    cin >> n; //수열 크기 입력
    vector<int> arr_pos, arr_neg; //양수 벡터, 음수 벡터
    while (n--) { //수열 전부 들어갈 때까지
        cin >> x; //수열의 수 입력
        if (x > 1) { //양수
            arr_pos.push_back(x); //벡터에 넣기
        }
        else if (x < 1) { //곱하면 작아지는 양수 or 음수
            arr_neg.push_back(x); //벡터에 넣기
        }
        else { //1
            cnt1++;
        }
    }

    //절댓값이 큰 순으로 정렬
    sort(arr_pos.begin(), arr_pos.end(), greater<>()); //양수 정렬
    sort(arr_neg.begin(), arr_neg.end()); //작아지는 양수 or 음수 정렬

    //연산 & 출력
    cout << cnt1 + tieNumber(arr_pos) + tieNumber(arr_neg); //곱하고 더한 최대합 출력
    return 0;
}