#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

//단지 내 집 개수 탐색하는 bfs
int bfs(int n, int r, int c, vector<vector<bool>>& board) {
    int dr[4] = { -1, 1, 0, 0 }; //상하좌우 계산을 위한 좌표
    int dc[4] = { 0, 0, -1, 1 };

    queue<ci> q; //bfs 계산을 위한 큐

    //큐 초기화
    q.push({ r, c }); //큐에 처음 좌표 값 넣기
    board[r][c] = false; //false로 설정
    int cnt = 1; //카운트 초기화
    while (!q.empty()) { //큐에 수가 있다면
        int cr = q.front().first; //그 수를 새로운 좌표로 설정한 후
        int cc = q.front().second;
        q.pop(); //큐에서 삭제

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i]; //상하좌우 좌표값 계산을 위해 새로운 좌표 설정
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || !board[nr][nc]) { 
                continue; //새로운 좌표가 전체 좌표 내부에 있지 않거나, 이미 큐에 존재하는 좌표인 경우 스킵
            }
            q.push({ nr, nc }); //새로운 좌표를 큐에 넣고
            board[nr][nc] = false; //큐에 존재한다는 것을 알림
            cnt++; //카운트
        }
    }
    return cnt; //전체 카운트를 반환(집 수)
}

//단지 수와 단지 내 집 개수 구하는 함수
vector<int> cntComplex(int n, vector<vector<bool>>& board) {
    vector<int> complex; //단지 수와 집 개수 벡터
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) { 
                int cnt = bfs(n, i, j, board); //집 수를 반환하여 cnt에 저장
                complex.push_back(cnt); //cnt를 단지 벡터에 넣어 단지 수 +1, 집 수 저장
            }
        }
    }
    return complex; //단지 벡터 반환
}

/**
 * [단지 번호 붙이기] - bfs
 *
 * 단순 탐색
 * (주의) 단지 내 집의 수를 "오름차순"으로 출력
 *
 * 이 풀이에서는 방문체크 배열을 따로 사용하지 않고, 처음 지도에 표기를 1 -> 0으로 바꾸어 중복으로 탐색하지 않도록 함
 */

int main() {
    int n; //지도의 크기
    string s; //집의 유무 입력 위한 스트링

    //입력
    cin >> n; //지도 크기 입력
    vector<vector<bool>> board(n, vector<bool>(n, false)); //집 유무 벡터
    for (int i = 0; i < n; i++) {
        cin >> s; //스트링 입력받기
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0'; //벡터에 넣기
        }
    }

    //연산
    vector<int> ans = cntComplex(n, board); //단지 구하기
    sort(ans.begin(), ans.end()); //단지 내 집 수 오름차순 정렬

    //출력
    cout << ans.size() << '\n'; //단지 수 출력
    for (int i = 0; i < ans.size(); i++) {//단지 내 집 수 출력
        cout << ans[i] << '\n';
    }
    return 0;
}