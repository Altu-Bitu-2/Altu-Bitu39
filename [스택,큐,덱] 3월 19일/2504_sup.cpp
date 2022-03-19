#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s) {
    stack<char> st; //괄호 합 확인할 스택
    map<char, int> num; //괄호 값
    map<char, char> bracket; //괄호 쌍

    //괄호 쌍과 값 저장
    bracket[')'] = '('; // () 괄호쌍
    bracket[']'] = '['; // [] 괄호쌍
    num['('] = 2; // () 괄호값
    num['['] = 3; // [] 괄호값

    int ans = 0, temp = 1;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '(': case '[': //여는 괄호일 경우
            st.push(s[i]); //스택에 저장
            temp *= num[s[i]];
            break;
        case ')': case ']': //닫는 괄호일 경우
            if (st.empty() || st.top() != bracket[s[i]]) { //스택이 비거나 짝이 안 맞는 경우
                return 0; //0 리턴
            }
            if (s[i - 1] == bracket[s[i]]) { //짝이 맞는 경우
                ans += temp;
            }
            temp /= num[bracket[s[i]]]; //이미 값을 더한 경우이므로 나누기
            st.pop(); //작업 완료 후 스택에서 빼내기
            break;
        }
    }
    if (st.empty()) { //(마지막까지 끝낸 후 스택이 비어 있는)올바른 괄호라면
        return ans; //제대로 된 정답 반환
    }
    return 0;
}

/**
 * "분배법칙"을 활용!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   임시변수값:  2   6 2     4  12   4   2   1
 * =>                        정답:        +6           +12        = 18
 *
 * 따라서, 우선 여는 괄호가 나오면 괄호의 값을 곱해줌
 * 닫는 괄호는, 이전 문자가 여는 괄호일 경우 지금까지 곱한 값을 더해줌 (값이 중복으로 더해지는 것을 방지하기 위해 이전 문자가 여는 괄호인지 꼭 체크!)
 *            한 괄호에 대한 연산이 끝났으므로 (곱하기 연산) 다시 괄호 값을 나눠줘서 연산 진행
 */

int main() {
    string s; //괄호 넣을 string

    //입력
    cin >> s; //string 입력
    //연산 & 출력
    cout << calc(s); //계산 내역 출력
    return 0;
}