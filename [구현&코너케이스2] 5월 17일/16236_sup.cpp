#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) {
    int dr[4] = { -1, 1, 0, 0 }; //이동을 위한 좌표
    int dc[4] = { 0, 0, -1, 1 }; //이동을 위한 좌표

    int min_dist = INF; //최단 거리를 구하기 위해 최대로 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1; //방문 여부를 위한 현 위치 설정
    q.push(shark); //현재 상어 위치 큐에 넣기
    while (!q.empty()) {
        int row = q.front().first; //큐에서 좌표 꺼내 설정
        int col = q.front().second; //큐에서 좌표 꺼내 설정
        q.pop(); //꺼낸 좌표 pop

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue; //다음으로
        }
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i]; //상하좌우 탐색을 위해 좌표 이동
            int nc = col + dc[i]; //상하좌우 탐색을 위해 좌표 이동
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) { //공간 외 좌표 or 방문 불가 or 더 큰 물고기
                continue; //불가능하므로 다음 좌표
            }

            dist[nr][nc] = dist[row][col] + 1; //거리 + 1
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); //먹을 수 있는 물고기 리스트에 추가
                min_dist = dist[nr][nc]; //최저 거리 설정
                continue; //다음 좌표 확인
            }
            q.push({ nr, nc }); //다음 확인할 좌표 큐에 넣기
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return { min_dist, {-1, -1} }; //최저 거리, 불가능 좌표 출력
    }

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) { //거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기
            return p1.first < p2.first;
        }
        return p1.second < p2.second; //가장 위에 있는 물고기가 여러 마리라면, 가장 왼쪽의 물고기
        });
    return { min_dist - 1, list[0] }; //최저 거리 - 방문 여부, 물고기 좌표
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) {
    int ans = 0, size = 2, cnt = 0; //먹은 물고기 수, 아기 상어 크기, 
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board);
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break; //연산 끝냄
        }
        ans += result.first; //필요한 거리 = 걸리는 시간
        cnt++; //물고기 수 카운트
        if (cnt == size) { //상어 크기와 같은 수의 물고기를 먹으면 상어 크기 증가
            cnt = 0; //물고기 수 초기화
            size++; //상어 크기 증가
        }

        //상어 이동
        board[shark.first][shark.second] = 0; //원래 상어 자리는 빈칸
        shark = result.second; //상어가 물고기 좌표로 이동
    }
    return ans; //결과값 반환
}

/**
 * [아기 상어]
 *
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

int main() {
    int n; //공간의 크기
    pair<int, int> shark_pos; //상어 위치 pair

    //입력
    cin >> n; //공간 크기 입력
    vector<vector<int>> board(n, vector<int>(n)); //공간 상태 벡터
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //각 공간 상태 입력
            if (board[i][j] == 9) { //아기 상어 위치라면
                shark_pos = make_pair(i, j); //상어 위치 설정
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board); //연산해 출력
    return 0;
}