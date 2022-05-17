#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

//알파벳별 등장횟수 저장 함수
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0); //알파벳별 등장횟수 저장 벡터
    for (int i = 0; i < str.size(); i++) { //단어의 각 알파벳 돌면서 확인
        result[str[i] - 'A']++; //벡터 사이즈에 맞추어 A를 빼고 저장
    }
    return result; //알파벳별 등장횟수 반환
}

/**
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

int main() {
    int n, ans = 0; //단어의 개수, 출력할 비슷한 단어의 개수
    string source, target; //첫 번째 단어와 다른 단어들

    //입력
    cin >> n >> source; //단어 개수, 첫 번째 단어 입력

    //연산
    vector<int> source_alpha = alphaMap(source); //첫 번째 단어 알파벳 확인
    while (--n) { //다른 단어들 전부 입력&연산할 때까지
        cin >> target; //다른 단어 입력

        int diff = 0; //차이를 확인할 변수
        vector<int> target_alpha = alphaMap(target); //다른 단어 알파벳 확인
        for (int i = 0; i < SIZE; i++) { //두 단어의 차이
            diff += abs(source_alpha[i] - target_alpha[i]); //차이가 있는 만큼 diff 증가
        }
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) { //문자를 더하거나, 빼거나, 바꾸거나
            ans++; //비슷한 단어 수 증가
        }
    }

    //출력
    cout << ans; //비슷한 단어 수 출력
    return 0;
}