#include <vector>
#include <iostream>

using namespace std;

vector<vector<vector<bool>>> board;

//현재 상태가 조건에 만족하는지 (x, y) 중심으로 확인
bool validate(int x, int y, int p, int n) { //x, y, 구조물종류, n
    //가능한 경우만 체크 후 나머지 false
    if (p == 0) { //기둥
        if (y == 0) { //바닥 위
            return true;
        }
        if (board[x][y][1] || (x > 0 && board[x - 1][y][1])) { //보의 왼쪽/오른쪽 끝
            return true;
        }
        if (y > 0 && board[x][y - 1][0]) { //기둥 위
            return true;
        }
    }
    else { //보
        if (y > 0 && board[x][y - 1][0]) { //왼쪽 끝이 기둥 위
            return true;
        }
        if (x < n && y > 0 && board[x + 1][y - 1][0]) { //오른쪽 끝이 기둥 위
            return true;
        }
        if (x > 0 && x < n && board[x - 1][y][1] && board[x + 1][y][1]) { //양쪽 끝이 보와 연결
            return true;
        }
    }
    return false; //위의 경우 이외에는 설치 불가능하므로 false 반환
}

//(x, y)에 있는 구조물을 삭제할 수 있는지 확인
bool checkRemovable(int x, int y, int n) {
    int dx[3] = { -1, 0, 1 }; //다른 좌표 확인을 위한 x좌표
    int dy[3] = { -1, 0, 1 }; //다른 좌표 확인을 위한 y좌표
    //기둥이 삭제된 경우, 해당 기둥 위에 보가 있었을 수 있으므로 (조건 2-b) 대각선도 확인이 필요
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int nx = x + dx[i]; //받아온 좌표 주변 확인을 위해 새롭게 x좌표 설정
            int ny = y + dy[j]; //y좌표
            if (nx < 0 || nx > n || ny < 0 || ny > n) { //주어진 n*n 좌표를 벗어나면
                continue; //멈추고 다음 좌표
            }
            for (int k = 0; k < 2; k++) { 
                if (board[nx][ny][k] && !validate(nx, ny, k, n)) { //해당 좌표의 구조물이 유지 불가능 시
                    return false; //원래대로 돌릴 수 있도록 false 출력
                }
            }
        }
    }
    return true; //다른 구조물에 영향을 주지 않으므로 삭제 가능 반환
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer; //반환할 최종 구조물 상태
    board.assign(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false))); //현재 설치 현황
    //시뮬레이션
    for (int i = 0; i < build_frame.size(); i++) { //설치&삭제 완료될 때까지 반복
        int x = build_frame[i][0]; //설치 x좌표
        int y = build_frame[i][1]; //설치 y좌표
        int p = build_frame[i][2]; //설치할 구조물 종류
        int cmd = build_frame[i][3]; //설치&삭제 여부
        if (!cmd) { //삭제
            board[x][y][p] = false; //구조물 삭제
            if (!checkRemovable(x, y, n)) { //삭제 불가능 시
                board[x][y][p] = true; //true로 되돌리기
            }
        }
        else if (validate(x, y, p, n)) { //설치 가능한 경우
            board[x][y][p] = true; //설치
        }
    }
    //결과
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                if (board[i][j][k]) {
                    answer.push_back({ i, j, k });; //작업 완료 후 반환할 최종 구조물 상태 벡터에 넣기
                }
            }
        }
    }
    return answer; //최종 구조물 반환
}

/**
 * [기둥과 보 설치]
 * 들어오는 입력에 대해 설치 또는 삭제 이후에도 기본 조건에 만족하는지 확인
 *
 * [기본 조건]
 * 1. 기둥
 *     a. 바닥 위
 *     b. 보의 한 쪽 끝
 *     c. 다른 기둥 위
 * 2. 보
 *     a. 한쪽 끝이 기둥 위
 *     b. 양쪽 끝이 보와 연결
 *
 * - 설치: 설치하려는 좌표가 조건을 만족하는지 확인
 * - 삭제: 해당 기둥/보를 삭제했을 시 영향을 받는 인접한 기둥/보가 여전히 조건을 만족하고 있는지 확인
 */
int main() {
    int n = 5; //벽면 크기
    vector<vector<int>> build_frame = { {1, 0, 0, 1}, //보&기둥 만들기
                                       {1, 1, 1, 1},
                                       {2, 1, 0, 1},
                                       {2, 2, 1, 1},
                                       {5, 0, 0, 1},
                                       {5, 1, 0, 1},
                                       {4, 2, 1, 1},
                                       {3, 2, 1, 1} };
    vector<vector<int>> ans = solution(n, build_frame); //설치&삭제 가능 여부 계산해 최종 구조물 상태 받아오기
    for (int i = 0; i < ans.size(); i++) { //최종 구조물 상태 출력
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}