#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

int n, ans = 0;

int getMaxBlock(matrix& board) {
    int max_block = 0; //가장 큰 블록 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_block = max(max_block, board[i][j]); //보드 돌면서 가장 큰 블록 찾기
        }
    }
    return max_block; //가장 큰 블록 반환
}

matrix transposeMatrix(matrix& board) {
    matrix board_t(n, vector<int>(n, 0)); //뒤집은 보드
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board_t[i][j] = board[j][i]; //대각선 기준으로 보드 뒤집기
        }
    }
    return board_t; //뒤집은 보드 반환
}

/**
 * 상으로 이동하는 함수
 * - 한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
 * - 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
 */
matrix upMove(matrix board) {
    matrix temp(n, vector<int>(n, 0)); //새롭게 블록 저장할 배열
    for (int j = 0; j < n; j++) { //세로 고정해 계산
        int idx = 0; //블록의 이동 기록용
        int prev = 0; //이전 블록과 비교하기 위해
        for (int i = 0; i < n; i++) {
            if (!board[i][j]) { //아무것도 없는 경우
                continue; //다음 행
            }
            if (board[i][j] == prev) { //이전 블록과 수가 같다면
                temp[idx - 1][j] *= 2; //현재 가능한 가장 위쪽 위치로 더해서 이동시킴
                prev = 0; //한번 더한 블록은 더이상 더할 수 없으므로 초기화
            }
            else {
                temp[idx++][j] = board[i][j]; //이전 블록과 수가 다르다면 가장 위쪽으로 이동시키고
                prev = board[i][j]; //이전 블록으로 설정
            }
        }
    }
    return temp; //새로운 블록 배열 반환
}

//백트래킹 탐색
void backtracking(int cnt, matrix board) {
    if (cnt == 5) { //5번 이동 완료 시
        ans = max(ans, getMaxBlock(board)); //결과 
        return;
    }
    //Transpose matrix 구하기 (상->좌)
    matrix board_t = transposeMatrix(board); //좌우 이동을 위해 보드 뒤집기
    //상
    backtracking(cnt + 1, upMove(board)); //이동 수 카운트, 새롭게 이동한 보드로 백트래킹
    //하
    reverse(board.begin(), board.end()); //상방향 이동이므로 위아래 보드 뒤집기
    backtracking(cnt + 1, upMove(board)); //이동 수 카운트, 새롭게 이동한 보드로 백트래킹
    //좌
    backtracking(cnt + 1, upMove(board_t));//이동 수 카운트, 새롭게 이동한 보드로 백트래킹
    //우
    reverse(board_t.begin(), board_t.end()); //왼쪽 이동 기준으로 보드를 뒤집었으므로 다시 뒤집기
    backtracking(cnt + 1, upMove(board_t));//이동 수 카운트, 새롭게 이동한 보드로 백트래킹
}

/**
 * [2048 (Easy)]
 *
 * - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 * - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦
 *
 * - 상 <-> 하: 행 순서를 뒤집어서 해결
 * - 상/하 <-> 좌/우: Transpose Matrix 활용
 *
 * - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
 *       2 2 2
 *       4 4 4
 *  -상: 원래 배열에서 상으로 움직이는 함수 실행
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    //입력
    cin >> n; //보드의 크기 입력
    matrix board(n, vector<int>(n, 0)); //보드 벡터 초기화
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //게임판 초기 상태 입력
        }
    }

    //연산
    backtracking(0, board); //2048 연산

    //출력
    cout << ans; //가장 큰 블록 출력
    return 0;
}