#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;
const int SIZE = 11;

int n;
vector<int> num(SIZE + 1);
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX; //최대, 최소 설정

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건) 최대, 최소 반환
        max_value = max(max_value, sum); 
        min_value = min(min_value, sum);
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {
            expression[i]--; //카운트--
            int new_sum = 0;
            switch (i) { //연산자 종류에 따라
            case 0: //덧셈
                new_sum = sum + num[cnt + 1];
                break;
            case 1: //뺄셈
                new_sum = sum - num[cnt + 1];
                break;
            case 2: //곱셈
                new_sum = sum * num[cnt + 1];
                break;
            case 3: //나눗셈
                new_sum = sum / num[cnt + 1];
                break;
            }
            backtracking(cnt + 1, new_sum); //연산을 완료할 때까지 재귀를 통해 계산
            expression[i]++; //다음 계산을 위해 재귀가 끝난 후 카운트 돌려놓기
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n; //수의 개수
    for (int i = 0; i < n; i++) { //수 입력
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) { //+-*/ 개수
        cin >> expression[i];
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value; //최댓값, 최솟값 출력
    return 0;
}