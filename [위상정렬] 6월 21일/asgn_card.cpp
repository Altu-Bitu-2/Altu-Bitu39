#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 4;

int dr[4] = { -1, 1, 0, 0 }; //��ǥ �̵��� ���� ����
int dc[4] = { 0, 0, -1, 1 };

//��Ʈ�ѷ� �̵��ϴ� ��ǥ�� �����ϴ� �Լ�
ci ctrl(int row, int col, int dir, vector<vector<int>>& tmp) {
    while (true) {
        row += dr[dir]; //�̵� ��ǥ
        col += dc[dir];
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) { //�ش� ���⿡ ī�尡 �ϳ��� ���ٸ� �� ������ ���� ������ ĭ���� �̵�
            return make_pair(row - dr[dir], col - dc[dir]); //�ش� ��ǥ ��ȯ
        }
        if (tmp[row][col] != 0) { //���� Ű ���⿡ �ִ� ���� ����� ī��
            return make_pair(row, col); //�ش� ��ǥ ��ȯ
        }
    }
}

//���� Ŀ������ ��ǥ ī��� �̵��ϴ� ���� ���� ����� �����ϴ� �Լ�
int bfs(int r1, int c1, int r2, int c2, vector<vector<int>>& tmp) {
    vector<vector<int>> visited(SIZE, vector<int>(SIZE, 0)); //�湮�� ��ġ �ľ�
    queue<ci> q; //bfs ����� ��ǥ ť
    visited[r1][c1] = 1; //�ݵ�� ���͸� ������ �� ��. ���͸� �̸� ������ �����ϰ� 1�� ǥ��
    q.push({ r1, c1 }); //�� ��ǥ ť�� �ֱ�

    while (!q.empty()) { //����� ���� ������ ������
        int row = q.front().first; //ť�� ù x ��ǥ
        int col = q.front().second; //ť�� ù y ��ǥ
        int dist = visited[row][col]; //�̵� ��� �ʱ�ȭ
        q.pop(); //��ǥ ����� �����̹Ƿ� ����

        if (row == r2 && col == c2) { //��ǥ ī�忡 �����ߴٸ�
            return dist;
        }
        for (int i = 0; i < 4; i++) { //��Ʈ�� �Է� �̵�
            pair<int, int> np = ctrl(row, col, i, tmp); //�̵��� ��ǥ
            if (visited[np.first][np.second]) { //�ƹ��͵� ���ٸ�
                continue; //���� �ݺ�
            }
            visited[np.first][np.second] = dist + 1; //�̵� ��� ++
            q.push(np); //�ش� ��ǥ ��� ���� ť�� �ֱ�
        }

        for (int i = 0; i < 4; i++) { //����Ű �Է� �̵�
            int nr = row + dr[i], nc = col + dc[i]; //4���� ��ǥ �ʱ�ȭ
            if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE || visited[nr][nc]) { //���� ������ �̵��ϰ� �ȴٸ�
                continue; //���� �ݺ�
            }
            visited[nr][nc] = dist + 1; //�̵� ���++
            q.push({ nr, nc }); //�ش� ��ǥ ��� ���� ť�� �ֱ�
        }
    }
    return -1; //��ǥ ī�忡 �������� ���� (�����δ� �Ͼ�� �ʴ� ��)
}

//���տ� ���� ī�带 ��Ī�ϴ� �Լ�
int matchCard(int bit, int num, int r, int c, int answer, vector<int>& seq, vector<vector<ci>>& cards,
    vector<vector<int>> tmp) {
    int ans = 0; //���� ��ȯ�� �� �ʱ�ȭ
    for (int i = 0; i < num; i++) {
        int cur = seq[i]; //�̹��� ��Ī�� ĳ����
        int now = 0; //�ش� ĳ������ 0��° ī����� �����Ѵٰ� ����
        if (bit & (1 << i)) { //���� �ش� ��ġ�� ��Ʈ�� 1�� ǥ���ߴٸ� 1��° ī����� ����
            now = 1;
        }
        for (int j = 0; j < 2; j++) {
            int nr = cards[cur][now].first, nc = cards[cur][now].second; //�̹��� ��Ī�� ī�� ��ġ
            ans += bfs(r, c, nr, nc, tmp); //���� Ŀ������ ��ǥ ī����� �̵��ϴ� ���
            //���� �ּڰ����� ū ��� -> �� �̻��� Ž�� ���ʿ�
            if (ans >= answer) {
                return answer;
            }
            //ī�� ���� + Ŀ�� �̵�
            tmp[nr][nc] = 0;
            r = nr;
            c = nc;
            now = 1 - now; //������ ��Ī�� ī�� �ε���
        }
    }
    return ans; //����� �ּڰ� ��ȯ
}

//�����ϴ� ��� ī���� ��ġ�� �����ϴ� �Լ�
vector<vector<ci>> findCard(vector<vector<int>>& board) {
    vector<vector<ci>> card_pos(7, vector<ci>(0)); //�ִ� ī�� ��
    int cnt = 0; //ī�� �� ����
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cnt = max(cnt, board[i][j]); //������ ��ȣ�� �ٸ��� �̿�
            if (board[i][j]) { //ī���� ��ġ ����
                card_pos[board[i][j]].push_back({ i, j });
            }
        }
    }
    card_pos.resize(cnt + 1); //���� �����ϴ� ī���� ����ŭ ũ�� ����
    return card_pos; //ī�� ��ġ ��ȯ
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9; //�ּڰ� ������ ���� �ʱ�ȭ
    vector<vector<ci>> cards = findCard(board); //�����ϴ� ��� ī���� ��ġ
    int card_cnt = cards.size() - 1; //ī���� ����

    vector<int> seq(card_cnt); //������ ���� �迭
    for (int i = 0; i < card_cnt; i++) {
        seq[i] = i + 1; //ī��� 1���� ����
    }
    do { //������ ��� ī�� ������ ����
        for (int bit = 0; bit < (1 << card_cnt); bit++) { //0, 1��° ī�� �� � ī�带 ���� �������� ����
            answer = min(answer, matchCard(bit, card_cnt, r, c, answer, seq, cards, board)); //�ּڰ��� ����� ���� ���� �� �� ����
        }
    } while (next_permutation(seq.begin(), seq.end())); //��� ����� ���� ���� ������
    return answer; //�ּڰ� ���
}

/**
 * [ī�� ¦ ���߱�]
 *
 * ���̵��
 * 1. ������ ũ�� ����
 * 2. �����ϴ� ��� ī���� ������ 6��, ī�� 2���� �� ���� �̷��.
 * 3. ������ ī�� ������ ���ϴ� ��� ����� ���� 6!(ī�� ����) * 2^6(2���� ī�� �� � ī�带 ���� ��������) -> ���Ʈ���� ����
 * 4. �̹��� ��ǥ�� �ϴ� ī�忡 ���� ���� Ŀ������ ��ǥ ī����� ���� �ִ� ��θ� ���ϸ� �̵� Ƚ�� ���� ���ϰ� �ּڰ� ����
 *
 * ����
 * 1. �����ϴ� ��� ī���� ��ġ�� �����ϸ� ī���� ���� ���� (findCard)
 * 2. ������ ��� ī���� ����(next_permutation)�� �� ī�带 ������ ����(bitmask)�� ����
 *    ex) seq = {3, 1, 2}, bit = 011 �� ��
 *        3��, 1��, 2�� ī���� ������ �����´�.
 *        3�� ī��� 1��° ī�����, 1�� ī��� 0��° ī�����, 2�� ī��� 1��° ī����� �����´�.
 *        bit�� 011�� �տ������� ���� 1, 2, 3�� ī��� ������
 * 3. ���� ī�� ������ �� ī�带 ������ ������ ���� Ŀ�� �̵� Ƚ�� ��� (matchCard)
 *    ���� Ŀ�� ��ġ�� ��ǥ ī�� ��ġ�� ���� bfs �Լ� ����
 *    ��Ʈ�� �Է��� ����ؾ� �ϱ� ������ 4���⿡ ���� ���� �̵��� �߰��� ��Ʈ�� �Էµ� ó���Ѵ�.(ctrl)
 * 4. �� ���տ� ���� board�� ���ŵǹǷ� board�� ������ tmp ���
 * ���� Ǯ�� : https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/
 */
int main() {
    vector<vector<int>> board = { {1, 0, 0, 3}, //������ ī�� �迭
                                 {2, 0, 0, 0},
                                 {0, 0, 0, 2},
                                 {3, 0, 1, 0} };
    cout << solution(board, 1, 0); //Ű ���� Ƚ�� �ּڰ� ����� ���
}