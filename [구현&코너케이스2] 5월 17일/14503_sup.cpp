#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) {
    //상, 우, 하, 좌
    int dr[4] = { -1, 0, 1, 0 }; //바라보는 방향에 따른 세로 좌표 이동을 위해
    int dc[4] = { 0, 1, 0, -1 }; //바라보는 방향에 따른 가로 좌표 이동을 위해

    int step = 0, ans = 0;
    while (true) {
        if (board[r][c] == 0) { //로봇 청소기 좌표가 빈칸인 경우
            board[r][c] = 2; //청소한 자리로 표시하고
            ans++; //청소한 칸 수 카운트
        }

        if (step == 4) { //한 바퀴 돌아 원래대로 돌아온 경우
            if (board[r - dr[d]][c - dc[d]] == 1) { //바라보는 방향의 반대가 벽일 경우(처음부터 갈 곳이 없는 경우)
                return ans; //결과 반환
            }
            r -= dr[d]; //반대 방향(들어온 방향)을 향하기
            c -= dc[d]; //반대 방향(들어온 방향)을 향하기
            step = 0; //회전 초기화
        }
        else {
            d = (d + 3) % 4;
            if (board[r + dr[d]][c + dc[d]]) { //이동 위치가 빈 칸이 아닌 경우
                step++; //회전
                continue; //이어서 진행
            }
            r += dr[d]; //세로 위치 이동
            c += dc[d]; //가로 위치 이동
            step = 0; //이미 이동해 한 바퀴 돌 일이 없으므로 초기화
        }
    }
}

/**
 * [로봇 청소기]
 *
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d; //세로 크기, 가로 크기, 로봇청소기 좌표 (r, c), 바라보는 방향

    //입력
    cin >> n >> m >> r >> c >> d; //세로, 가로, 로봇청소기 정보 입력
    vector<vector<int>> board(n, vector<int>(m, 0)); //각 칸의 정보 벡터
    for (int i = 0; i < n; i++) { //세로 돌기
        for (int j = 0; j < m; j++) { //가로 돌기
            cin >> board[i][j]; //각 칸의 정보 입력
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board); //결과 출력
    return 0;
}