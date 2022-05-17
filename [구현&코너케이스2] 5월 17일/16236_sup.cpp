#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) {
    int dr[4] = { -1, 1, 0, 0 }; //�̵��� ���� ��ǥ
    int dc[4] = { 0, 0, -1, 1 }; //�̵��� ���� ��ǥ

    int min_dist = INF; //�ִ� �Ÿ��� ���ϱ� ���� �ִ�� �ʱ�ȭ
    queue<ci> q; //�� �� �� �ִ� ��
    vector<vector<int>> dist(n, vector<int>(n, 0)); //����� �湮 ���� + �Ÿ�
    vector<ci> list; //�� ���� �� �ִ� �������� ��ġ

    dist[shark.first][shark.second] = 1; //�湮 ���θ� ���� �� ��ġ ����
    q.push(shark); //���� ��� ��ġ ť�� �ֱ�
    while (!q.empty()) {
        int row = q.front().first; //ť���� ��ǥ ���� ����
        int col = q.front().second; //ť���� ��ǥ ���� ����
        q.pop(); //���� ��ǥ pop

        if (dist[row][col] >= min_dist) { //�ִܰŸ� �̻��� Ž���� �ʿ� ����
            continue; //��������
        }
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i]; //�����¿� Ž���� ���� ��ǥ �̵�
            int nc = col + dc[i]; //�����¿� Ž���� ���� ��ǥ �̵�
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) { //���� �� ��ǥ or �湮 �Ұ� or �� ū �����
                continue; //�Ұ����ϹǷ� ���� ��ǥ
            }

            dist[nr][nc] = dist[row][col] + 1; //�Ÿ� + 1
            if (board[nr][nc] && board[nr][nc] < shark_size) { //���� �� �ִ� ����� �߰�
                list.emplace_back(nr, nc); //���� �� �ִ� ����� ����Ʈ�� �߰�
                min_dist = dist[nr][nc]; //���� �Ÿ� ����
                continue; //���� ��ǥ Ȯ��
            }
            q.push({ nr, nc }); //���� Ȯ���� ��ǥ ť�� �ֱ�
        }
    }

    if (list.empty()) { //�� �� �� �ִ� ���� ����
        return { min_dist, {-1, -1} }; //���� �Ÿ�, �Ұ��� ��ǥ ���
    }

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //���� (compare �Լ��� �������� �ʾƵ� ��)
        if (p1.first != p2.first) { //�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����
            return p1.first < p2.first;
        }
        return p1.second < p2.second; //���� ���� �ִ� ����Ⱑ ���� �������, ���� ������ �����
        });
    return { min_dist - 1, list[0] }; //���� �Ÿ� - �湮 ����, ����� ��ǥ
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) {
    int ans = 0, size = 2, cnt = 0; //���� ����� ��, �Ʊ� ��� ũ��, 
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board);
        if (result.first == INF) { //�� �̻� ���� �� �ִ� ����Ⱑ ������ ����
            break; //���� ����
        }
        ans += result.first; //�ʿ��� �Ÿ� = �ɸ��� �ð�
        cnt++; //����� �� ī��Ʈ
        if (cnt == size) { //��� ũ��� ���� ���� ����⸦ ������ ��� ũ�� ����
            cnt = 0; //����� �� �ʱ�ȭ
            size++; //��� ũ�� ����
        }

        //��� �̵�
        board[shark.first][shark.second] = 0; //���� ��� �ڸ��� ��ĭ
        shark = result.second; //�� ����� ��ǥ�� �̵�
    }
    return ans; //����� ��ȯ
}

/**
 * [�Ʊ� ���]
 *
 * 1. ���κ��� ���� ����� �Ÿ��� �ִ� ��� ����� Ž�� (BFS)
 * 2. �켱���� ���ǿ� ���߾� ������ �� ����� Ȯ��
 *    Ž���ϴ� ���⿡ �켱������ �δ� �ɷ� �ذ���� ����! (���� �Է� 4) ���� �ʿ�
 * 3. �� �̵��� �� �ִ� ���� ���� ������ BFS Ž�� �ݺ�
 *
 * �Է� ������ �۱� ������ �Ź� BFS Ž���� �ݺ��ص� �ð� �ʰ� X
 * ������ ������� �ִ� ���� �� : 399����
 * �ִ� BFS Ž�� Ƚ�� : 399ȸ, 1ȸ Ž������ while ���� �ִ� 400ȸ �̸����� ��ȸ
 * �� ���� Ƚ�� �� 160000������ ����� ����
 *
 * �ؼ� : https://myunji.tistory.com/378
 * *�� ��ü�� ���� ������ �ȵǰ�...�׳� �����丵�ϸ� �ڵ尡 �̷��� �Ǵ±��� ������ ���ּ���
 */

int main() {
    int n; //������ ũ��
    pair<int, int> shark_pos; //��� ��ġ pair

    //�Է�
    cin >> n; //���� ũ�� �Է�
    vector<vector<int>> board(n, vector<int>(n)); //���� ���� ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //�� ���� ���� �Է�
            if (board[i][j] == 9) { //�Ʊ� ��� ��ġ���
                shark_pos = make_pair(i, j); //��� ��ġ ����
            }
        }
    }

    //���� & ���
    cout << simulation(n, shark_pos, board); //������ ���
    return 0;
}