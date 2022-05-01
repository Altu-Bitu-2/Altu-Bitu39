#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

//���� �� �� ���� Ž���ϴ� bfs
int bfs(int n, int r, int c, vector<vector<bool>>& board) {
    int dr[4] = { -1, 1, 0, 0 }; //�����¿� ����� ���� ��ǥ
    int dc[4] = { 0, 0, -1, 1 };

    queue<ci> q; //bfs ����� ���� ť

    //ť �ʱ�ȭ
    q.push({ r, c }); //ť�� ó�� ��ǥ �� �ֱ�
    board[r][c] = false; //false�� ����
    int cnt = 1; //ī��Ʈ �ʱ�ȭ
    while (!q.empty()) { //ť�� ���� �ִٸ�
        int cr = q.front().first; //�� ���� ���ο� ��ǥ�� ������ ��
        int cc = q.front().second;
        q.pop(); //ť���� ����

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i]; //�����¿� ��ǥ�� ����� ���� ���ο� ��ǥ ����
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || !board[nr][nc]) { 
                continue; //���ο� ��ǥ�� ��ü ��ǥ ���ο� ���� �ʰų�, �̹� ť�� �����ϴ� ��ǥ�� ��� ��ŵ
            }
            q.push({ nr, nc }); //���ο� ��ǥ�� ť�� �ְ�
            board[nr][nc] = false; //ť�� �����Ѵٴ� ���� �˸�
            cnt++; //ī��Ʈ
        }
    }
    return cnt; //��ü ī��Ʈ�� ��ȯ(�� ��)
}

//���� ���� ���� �� �� ���� ���ϴ� �Լ�
vector<int> cntComplex(int n, vector<vector<bool>>& board) {
    vector<int> complex; //���� ���� �� ���� ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) { 
                int cnt = bfs(n, i, j, board); //�� ���� ��ȯ�Ͽ� cnt�� ����
                complex.push_back(cnt); //cnt�� ���� ���Ϳ� �־� ���� �� +1, �� �� ����
            }
        }
    }
    return complex; //���� ���� ��ȯ
}

/**
 * [���� ��ȣ ���̱�] - bfs
 *
 * �ܼ� Ž��
 * (����) ���� �� ���� ���� "��������"���� ���
 *
 * �� Ǯ�̿����� �湮üũ �迭�� ���� ������� �ʰ�, ó�� ������ ǥ�⸦ 1 -> 0���� �ٲپ� �ߺ����� Ž������ �ʵ��� ��
 */

int main() {
    int n; //������ ũ��
    string s; //���� ���� �Է� ���� ��Ʈ��

    //�Է�
    cin >> n; //���� ũ�� �Է�
    vector<vector<bool>> board(n, vector<bool>(n, false)); //�� ���� ����
    for (int i = 0; i < n; i++) {
        cin >> s; //��Ʈ�� �Է¹ޱ�
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0'; //���Ϳ� �ֱ�
        }
    }

    //����
    vector<int> ans = cntComplex(n, board); //���� ���ϱ�
    sort(ans.begin(), ans.end()); //���� �� �� �� �������� ����

    //���
    cout << ans.size() << '\n'; //���� �� ���
    for (int i = 0; i < ans.size(); i++) {//���� �� �� �� ���
        cout << ans[i] << '\n';
    }
    return 0;
}