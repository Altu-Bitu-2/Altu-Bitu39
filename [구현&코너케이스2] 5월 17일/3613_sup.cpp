#include <iostream>

using namespace std;

bool isCpp(string str) { //c++ 형식인가?
    for (int i = 0; i < str.size(); i++) { //스트링 한 글자씩 돌았을 때
        if (isupper(str[i])) { //대문자가 있으면
            return false; //false
        }
        if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) { //첫 or 마지막 글자가 '_' 또는 '_'가 연속 등장하면
            return false; //false
        }
    }
    return true; //부합할 경우 true 반환
}

bool isJava(string str) { //java 형식인가?
    return !isupper(str[0]) && str.find('_') == string::npos; //첫 글자가 대문자거나, '_'가 있으면 안됨
}

string toCpp(string str) { //java 형식을 c++로
    string result; //반환할 것
    for (int i = 0; i < str.size(); i++) { //스트링 한 글자씩 돌기
        if (isupper(str[i])) { //대문자라면
            result += '_'; //'_' 넣기
        }
        result += tolower(str[i]); //소문자로 바꾸기
    }
    return result; //변환한 것 반환
}

string toJava(string str) { //c++ 형식을 java로
    string result; //반환할 것
    for (int i = 0; i < str.size(); i++) { //스트링 한 글자씩 돌기
        if (str[i] == '_') { //'_' 라면
            result += toupper(str[i + 1]); //다음 글자 대문자로 바꾸기
            i++; //'_'를 넣었으므로 글자 수 증가
            continue; //다음 글자
        }
        result += str[i]; //나머지 글자는 그냥 삽입
    }
    return result; //변환한 것 반환
}

/**
 * [Java vs C++]
 *
 * 1. 입력으로 주어진 변수가 C++ 형식에도 맞고, JAVA 형식에도 맞을 수 있음 (ex. name)
 * 2. "Error!"인 경우 (C++)
 *    2-1. 언더바('_')로 시작하거나, 끝나는 변수
 *    2-2. 언더바('_')가 연속해서 등장하는 변수
 *    2-3. 대문자가 등장하는 변수
 * 3. "Error!"인 경우 (Java)
 *    3-1. 대문자로 시작하는 변수
 *    3-2. 언더바('_')가 등장하는 변수
 */

int main() {
    string str; //변수명

    cin >> str; //변수명 입력
    bool is_cpp = isCpp(str); //변수명이 cpp인지
    bool is_java = isJava(str); //변수명이 java인지

    if (is_cpp && is_java) { //두 형식에 모두 부합하면
        cout << str; //그대로 출력
    }
    else if (is_cpp) { //c++ 형식이라면
        cout << toJava(str); //java로 바꿔 출력
    }
    else if (is_java) { //java 형식이라면
        cout << toCpp(str); //cpp로 바꿔 출력
    }
    else { //둘 다 아니라면
        cout << "Error!"; //에러 메세지 출력
    }
    return 0;
}