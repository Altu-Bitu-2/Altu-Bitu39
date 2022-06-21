#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {
    for (int i = number; i <= n; i += number) { //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i];
    }
    return switches; //바꾼 스위치 상태 반환
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {
    switches[number] = !switches[number]; //받은 번호의 스위치 바꾸기
    for (int i = 1; i < number; i++) {
        if ((number + i > n) || (switches[number - i] != switches[number + i])) { //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break; //스위치 바꾸기를 그만두기
        }
        switches[number - i] = !switches[number - i]; //조건을 만족하는 경우 왼쪽 스위치 바꾸기
        switches[number + i] = !switches[number + i]; //오른족 스위치도 바꿔준다
    }
    return switches; //바꾼 스위치 상태 변환
}

/**
 * [스위치 켜고 끄기]
 *
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m; //스위치 개수, 학생 수
    int student, number; //학생 성별, 학생이 받은 수

    //입력
    cin >> n; //스위치 개수 입력
    vector<int> switches(n + 1, 0); //스위치 상태 벡터
    for (int i = 1; i <= n; i++) {
        cin >> switches[i]; //스위치 상태 입력
    }

    //입력 & 연산
    cin >> m; //학생 수 
    while (m--) {
        cin >> student >> number; //학생 성별, 받은 수 입력
        if (student == 1) { //남학생인 경우
            switches = changeSwitchBoy(n, number, switches); //계산해 스위치 상태 변경
        }
        else { //여학생인 경우
            switches = changeSwitchGirl(n, number, switches); //계산해 스위치 상태 변경
        }
    }

    //출력
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' '; //스위치 상태 출력
        if (i % 20 == 0) { //20개씩 출력할 수 있도록
            cout << '\n';
        }
    }
    return 0;
}