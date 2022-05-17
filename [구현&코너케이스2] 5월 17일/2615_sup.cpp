#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE && board[r][c] == stone; //바둑판 위에 있는지, 돌 종류가 맞는지 확인
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = { 0, 1, 1, -1 }; //세로 방향에 따른 확인을 위한 좌표
    int dc[4] = { 1, 0, 1, 1 }; //가로 방향에 따른 확인을 위한 좌표

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    if (promising(r - dr[d], c - dc[d], stone, board)) { //이전 위치 돌 확인
        return false; //있다면 false
    }
    int cnt = 0; //카운트 초기화
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++; //5개가 이어지는지 확인하기 위한 카운트
        r += dr[d]; //다음으로 이어지는 좌표
        c += dc[d]; //다음으로 이어지는 좌표
    }
    return cnt == 5; //5개가 이어지는 게 맞다면 true
}

bool isEnd(int r, int c, vector<vector<int>>& board) {
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) { //오목이 이루어져 승리했다면
            return true; //true 반환
        }
    }
    return false; //오목이 만들어지지 않았다면 false 반환
}

/**
 * [오목]
 *
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. (주의) 육목이상이 되는지 확인해야 함
 *
 */

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); //바둑판 벡터

    //입력
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j]; //바둑판 위 바둑알 상황 입력
        }
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) { //돌이 없음
                continue; //이어서 계산
            }
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; //이긴 바둑알 색, 가로줄 번호, 세로줄 번호 출력
                return 0; //0 반환해 끝내기
            }
        }
    }
    cout << 0; //승부가 결정나지 않은 경우 0 출력해 끝내기
    return 0;
}