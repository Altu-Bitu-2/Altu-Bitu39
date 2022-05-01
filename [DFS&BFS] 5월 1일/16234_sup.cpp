#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited;
queue<ci> countries; //BFS 탐색 위한 큐


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci>& union_cord) {
    for (int i = 0; i < union_cord.size(); i++) { //인구 이동이 가능한 나라만큼
        int row = union_cord[i].first, col = union_cord[i].second; //x,y 좌표 설정해
        board[row][col] = population; //population 받으면서 계산한 인구로 설정
        countries.push({ row, col }); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우 각 칸의 좌표 설정을 위한 초기화
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({ cr, cc }); //체크할 좌표 넣기
    queue<ci> q; //연합할 나라를 체크하기 위한 큐
    q.push({ cr, cc }); //큐에 좌표 넣기
    int sum = board[cr][cc], cnt = 1; //전체 인구수에 추가, 카운트 초기화
    while (!q.empty()) { //큐가 비어있지 않다면(다음 체크할 좌표가 있다면)
        cr = q.front().first; //새로운 좌표로 cr, cc 설정 후
        cc = q.front().second;
        q.pop(); //큐에서 삭제

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i]; //체크할 좌표의 상하좌우 좌표 설정
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) { 
                continue;//상하좌우 좌표가 전체 좌표의 내부에 존재하지 않거나 이미 큐에 존재하는 좌표인 경우
            }
            int diff = abs(board[nr][nc] - board[cr][cc]); //처음 좌표에서 끝 좌표까지 길이
            if (diff >= l && diff <= r) { //국경선 열림 //길이가 좌표를 벗어나지 않는다면
                q.push({ nr, nc }); //해당 좌표를 큐에 추가하고
                visited[nr][nc] = day; //인구이동하는 좌표로 설정
                union_cord.push_back({ nr, nc }); //연합에 추가
                sum += board[nr][nc]; //인구 수 추가
                cnt++; //카운트 초기화
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true; //true 반환
    }
    return false; //끝난 경우 false 반환
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    while (true) {
        day++; //날이 지나면 day 카운트
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) { //탐색 가능한 나라가 없어질 때까지
            int row = countries.front().first; //visited에 좌표 옮기기 위한 초기화
            int col = countries.front().second; 
            countries.pop(); //좌표 옮긴 후 큐에서 삭제
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue; //스킵
            }
            visited[row][col] = day; //탐색하는 나라는 day를 카운트해 방문 체크용 설정
            if (bfs(n, l, r, row, col, day)) { //인구 이동이 가능하다면
                is_move = true; //true로 설정
            }
        }
        if (!is_move) { //이동이 불가능하면
            return day - 1; //더 이상 체크하지 않도록 설정
        }
    }
}

/**
 * [인구 이동]
 *
 * 0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
 * 1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
 * 2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
 *    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
 *    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
 * 3. 인구이동이 전혀 일어나지 않을 때까지 반복
 */

int main() {
    int n, l, r; //땅의 크기, 인구 차 L명 이상 R명 이하

    //입력
    cin >> n >> l >> r;
    board.assign(n, vector<int>(n, 0)); //각 나라의 인구 벡터
    visited.assign(n, vector<int>(n, 0)); //탐색 가능한 나라의 좌표 입력 위한 벡터
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //각 나라의 인구 입력
            countries.push({ i, j }); //큐에 모든 좌표 저장
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r); //연산 후 출력
    return 0;
}