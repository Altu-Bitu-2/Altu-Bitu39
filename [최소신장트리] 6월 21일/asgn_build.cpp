#include <vector>
#include <iostream>

using namespace std;

vector<vector<vector<bool>>> board;

//���� ���°� ���ǿ� �����ϴ��� (x, y) �߽����� Ȯ��
bool validate(int x, int y, int p, int n) { //x, y, ����������, n
    //������ ��츸 üũ �� ������ false
    if (p == 0) { //���
        if (y == 0) { //�ٴ� ��
            return true;
        }
        if (board[x][y][1] || (x > 0 && board[x - 1][y][1])) { //���� ����/������ ��
            return true;
        }
        if (y > 0 && board[x][y - 1][0]) { //��� ��
            return true;
        }
    }
    else { //��
        if (y > 0 && board[x][y - 1][0]) { //���� ���� ��� ��
            return true;
        }
        if (x < n && y > 0 && board[x + 1][y - 1][0]) { //������ ���� ��� ��
            return true;
        }
        if (x > 0 && x < n && board[x - 1][y][1] && board[x + 1][y][1]) { //���� ���� ���� ����
            return true;
        }
    }
    return false; //���� ��� �̿ܿ��� ��ġ �Ұ����ϹǷ� false ��ȯ
}

//(x, y)�� �ִ� �������� ������ �� �ִ��� Ȯ��
bool checkRemovable(int x, int y, int n) {
    int dx[3] = { -1, 0, 1 }; //�ٸ� ��ǥ Ȯ���� ���� x��ǥ
    int dy[3] = { -1, 0, 1 }; //�ٸ� ��ǥ Ȯ���� ���� y��ǥ
    //����� ������ ���, �ش� ��� ���� ���� �־��� �� �����Ƿ� (���� 2-b) �밢���� Ȯ���� �ʿ�
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int nx = x + dx[i]; //�޾ƿ� ��ǥ �ֺ� Ȯ���� ���� ���Ӱ� x��ǥ ����
            int ny = y + dy[j]; //y��ǥ
            if (nx < 0 || nx > n || ny < 0 || ny > n) { //�־��� n*n ��ǥ�� �����
                continue; //���߰� ���� ��ǥ
            }
            for (int k = 0; k < 2; k++) { 
                if (board[nx][ny][k] && !validate(nx, ny, k, n)) { //�ش� ��ǥ�� �������� ���� �Ұ��� ��
                    return false; //������� ���� �� �ֵ��� false ���
                }
            }
        }
    }
    return true; //�ٸ� �������� ������ ���� �����Ƿ� ���� ���� ��ȯ
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer; //��ȯ�� ���� ������ ����
    board.assign(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false))); //���� ��ġ ��Ȳ
    //�ùķ��̼�
    for (int i = 0; i < build_frame.size(); i++) { //��ġ&���� �Ϸ�� ������ �ݺ�
        int x = build_frame[i][0]; //��ġ x��ǥ
        int y = build_frame[i][1]; //��ġ y��ǥ
        int p = build_frame[i][2]; //��ġ�� ������ ����
        int cmd = build_frame[i][3]; //��ġ&���� ����
        if (!cmd) { //����
            board[x][y][p] = false; //������ ����
            if (!checkRemovable(x, y, n)) { //���� �Ұ��� ��
                board[x][y][p] = true; //true�� �ǵ�����
            }
        }
        else if (validate(x, y, p, n)) { //��ġ ������ ���
            board[x][y][p] = true; //��ġ
        }
    }
    //���
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                if (board[i][j][k]) {
                    answer.push_back({ i, j, k });; //�۾� �Ϸ� �� ��ȯ�� ���� ������ ���� ���Ϳ� �ֱ�
                }
            }
        }
    }
    return answer; //���� ������ ��ȯ
}

/**
 * [��հ� �� ��ġ]
 * ������ �Է¿� ���� ��ġ �Ǵ� ���� ���Ŀ��� �⺻ ���ǿ� �����ϴ��� Ȯ��
 *
 * [�⺻ ����]
 * 1. ���
 *     a. �ٴ� ��
 *     b. ���� �� �� ��
 *     c. �ٸ� ��� ��
 * 2. ��
 *     a. ���� ���� ��� ��
 *     b. ���� ���� ���� ����
 *
 * - ��ġ: ��ġ�Ϸ��� ��ǥ�� ������ �����ϴ��� Ȯ��
 * - ����: �ش� ���/���� �������� �� ������ �޴� ������ ���/���� ������ ������ �����ϰ� �ִ��� Ȯ��
 */
int main() {
    int n = 5; //���� ũ��
    vector<vector<int>> build_frame = { {1, 0, 0, 1}, //��&��� �����
                                       {1, 1, 1, 1},
                                       {2, 1, 0, 1},
                                       {2, 2, 1, 1},
                                       {5, 0, 0, 1},
                                       {5, 1, 0, 1},
                                       {4, 2, 1, 1},
                                       {3, 2, 1, 1} };
    vector<vector<int>> ans = solution(n, build_frame); //��ġ&���� ���� ���� ����� ���� ������ ���� �޾ƿ���
    for (int i = 0; i < ans.size(); i++) { //���� ������ ���� ���
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}