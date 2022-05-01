#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited;
queue<ci> countries; //BFS Ž�� ���� ť


//�� ������ �α� ����ŭ �α� �̵��ϴ� �Լ�
void movePeople(int population, vector<ci>& union_cord) {
    for (int i = 0; i < union_cord.size(); i++) { //�α� �̵��� ������ ����ŭ
        int row = union_cord[i].first, col = union_cord[i].second; //x,y ��ǥ ������
        board[row][col] = population; //population �����鼭 ����� �α��� ����
        countries.push({ row, col }); //�α� �̵��� �ִ� ����� �������� �α� �̵� ���ɼ� ����
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //��, ��, ��, �� �� ĭ�� ��ǥ ������ ���� �ʱ�ȭ
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    vector<ci> union_cord; //���� ������ ����
    union_cord.push_back({ cr, cc }); //üũ�� ��ǥ �ֱ�
    queue<ci> q; //������ ���� üũ�ϱ� ���� ť
    q.push({ cr, cc }); //ť�� ��ǥ �ֱ�
    int sum = board[cr][cc], cnt = 1; //��ü �α����� �߰�, ī��Ʈ �ʱ�ȭ
    while (!q.empty()) { //ť�� ������� �ʴٸ�(���� üũ�� ��ǥ�� �ִٸ�)
        cr = q.front().first; //���ο� ��ǥ�� cr, cc ���� ��
        cc = q.front().second;
        q.pop(); //ť���� ����

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i]; //üũ�� ��ǥ�� �����¿� ��ǥ ����
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) { 
                continue;//�����¿� ��ǥ�� ��ü ��ǥ�� ���ο� �������� �ʰų� �̹� ť�� �����ϴ� ��ǥ�� ���
            }
            int diff = abs(board[nr][nc] - board[cr][cc]); //ó�� ��ǥ���� �� ��ǥ���� ����
            if (diff >= l && diff <= r) { //���漱 ���� //���̰� ��ǥ�� ����� �ʴ´ٸ�
                q.push({ nr, nc }); //�ش� ��ǥ�� ť�� �߰��ϰ�
                visited[nr][nc] = day; //�α��̵��ϴ� ��ǥ�� ����
                union_cord.push_back({ nr, nc }); //���տ� �߰�
                sum += board[nr][nc]; //�α� �� �߰�
                cnt++; //ī��Ʈ �ʱ�ȭ
            }
        }
    }
    if (cnt > 1) { //������ ����ٸ�
        movePeople(sum / cnt, union_cord); //�α� �̵�
        return true; //true ��ȯ
    }
    return false; //���� ��� false ��ȯ
}

int simulation(int n, int l, int r) {
    int day = 0; //�湮 üũ�ε� ���
    while (true) {
        day++; //���� ������ day ī��Ʈ
        bool is_move = false; //�α� �̵� �ߴ��� üũ
        int size = countries.size(); //�̹� �ð��� Ž���� �� �ִ� ������ ��
        while (size--) { //Ž�� ������ ���� ������ ������
            int row = countries.front().first; //visited�� ��ǥ �ű�� ���� �ʱ�ȭ
            int col = countries.front().second; 
            countries.pop(); //��ǥ �ű� �� ť���� ����
            if (visited[row][col] == day) { //�̹� Ž���� ������
                continue; //��ŵ
            }
            visited[row][col] = day; //Ž���ϴ� ����� day�� ī��Ʈ�� �湮 üũ�� ����
            if (bfs(n, l, r, row, col, day)) { //�α� �̵��� �����ϴٸ�
                is_move = true; //true�� ����
            }
        }
        if (!is_move) { //�̵��� �Ұ����ϸ�
            return day - 1; //�� �̻� üũ���� �ʵ��� ����
        }
    }
}

/**
 * [�α� �̵�]
 *
 * 0. �α��̵��� �Ͼ �� �ִ� ����(ó������ ��� ����)�� ��ǥ�� ��ǥ ť�� ����
 * 1. bfs Ž���� ���� ������ Ȯ���ϰ�, ���տ� ���Ե� ������ �α��̵��� �����Ѵ�.
 * 2. �α� �̵��� �־��� ����� ���� ������ �α��̵��� ���۵� �� �����Ƿ� ��ǥ ť�� �ٽ� �־��ش�.
 *    -> ���� �̵��� �־��� ���� ���ؼ��� bfs Ž�� ����
 *    - �α� �̵��� �Ͼ�� ���� �� ���� ���̿����� ���� ������ �α��̵��� �Ͼ �� ����
 * 3. �α��̵��� ���� �Ͼ�� ���� ������ �ݺ�
 */

int main() {
    int n, l, r; //���� ũ��, �α� �� L�� �̻� R�� ����

    //�Է�
    cin >> n >> l >> r;
    board.assign(n, vector<int>(n, 0)); //�� ������ �α� ����
    visited.assign(n, vector<int>(n, 0)); //Ž�� ������ ������ ��ǥ �Է� ���� ����
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //�� ������ �α� �Է�
            countries.push({ i, j }); //ť�� ��� ��ǥ ����
        }
    }

    //���� & ���
    cout << simulation(n, l, r); //���� �� ���
    return 0;
}