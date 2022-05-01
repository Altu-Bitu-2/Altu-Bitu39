#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int>& num, int left, int right, int idx) {
    while (left < right) { //서로 만날 때까지
        if (left == idx) { //만드는 수와 left가 겹칠 경우
            left++; //left 옮기기
            continue;
        }
        if (right == idx) { //만드는 수와 right가 겹칠 경우
            right--; //right 옮기기
            continue;
        }

        if (num[left] + num[right] == num[idx]) { //left+right가 만드는 수일 경우
            return true; //true를 리턴해 카운트하도록
        }
        if (num[left] + num[right] > num[idx]) { //left+right가 만드는 수보다 큰 경우
            right--; //right를 옮겨 더 작은 수가 되도록
        }
        else { //left+right가 만드는 수보다 작을 경우
            left++; //left를 옮겨 더 큰 수가 되도록
        }
    }
    return false; //true에 해당하지 않는다면 false 리턴해 카운트되지 않도록 함
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0; //수의 개수, good 개수 카운트 초기화

    //입력
    cin >> n; //수의 개수 입력
    vector<int> num(n, 0); //넣는 수 벡터
    for (int i = 0; i < n; i++) { //각 수 입력
        cin >> num[i];
    }

    //연산
    sort(num.begin(), num.end()); //오름차순 정렬
    for (int i = 0; i < n; i++) { //각 수를 판별하기 위한 for문
        if (isGood(num, 0, n - 1, i)) { //각 수 판별
            ans++; //good이라면 카운트
        }
    }

    //출력
    cout << ans; //good 개수 출력
    return 0;
}