#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

int n, ans = 0;

int getMaxBlock(matrix& board) {
    int max_block = 0; //���� ū ��� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_block = max(max_block, board[i][j]); //���� ���鼭 ���� ū ��� ã��
        }
    }
    return max_block; //���� ū ��� ��ȯ
}

matrix transposeMatrix(matrix& board) {
    matrix board_t(n, vector<int>(n, 0)); //������ ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board_t[i][j] = board[j][i]; //�밢�� �������� ���� ������
        }
    }
    return board_t; //������ ���� ��ȯ
}

/**
 * ������ �̵��ϴ� �Լ�
 * - �� ���� �˻��ϸ鼭 ���� ����� 2���� ���� �� �ִٸ� ��ġ��
 * - �̶� ��� ���� �κ��� �Ѿ��, ����� �����ߴ� ���� �����ؼ� ���ϴ� ���� �߿�!
 */
matrix upMove(matrix board) {
    matrix temp(n, vector<int>(n, 0)); //���Ӱ� ��� ������ �迭
    for (int j = 0; j < n; j++) { //���� ������ ���
        int idx = 0; //����� �̵� ��Ͽ�
        int prev = 0; //���� ��ϰ� ���ϱ� ����
        for (int i = 0; i < n; i++) {
            if (!board[i][j]) { //�ƹ��͵� ���� ���
                continue; //���� ��
            }
            if (board[i][j] == prev) { //���� ��ϰ� ���� ���ٸ�
                temp[idx - 1][j] *= 2; //���� ������ ���� ���� ��ġ�� ���ؼ� �̵���Ŵ
                prev = 0; //�ѹ� ���� ����� ���̻� ���� �� �����Ƿ� �ʱ�ȭ
            }
            else {
                temp[idx++][j] = board[i][j]; //���� ��ϰ� ���� �ٸ��ٸ� ���� �������� �̵���Ű��
                prev = board[i][j]; //���� ������� ����
            }
        }
    }
    return temp; //���ο� ��� �迭 ��ȯ
}

//��Ʈ��ŷ Ž��
void backtracking(int cnt, matrix board) {
    if (cnt == 5) { //5�� �̵� �Ϸ� ��
        ans = max(ans, getMaxBlock(board)); //��� 
        return;
    }
    //Transpose matrix ���ϱ� (��->��)
    matrix board_t = transposeMatrix(board); //�¿� �̵��� ���� ���� ������
    //��
    backtracking(cnt + 1, upMove(board)); //�̵� �� ī��Ʈ, ���Ӱ� �̵��� ����� ��Ʈ��ŷ
    //��
    reverse(board.begin(), board.end()); //����� �̵��̹Ƿ� ���Ʒ� ���� ������
    backtracking(cnt + 1, upMove(board)); //�̵� �� ī��Ʈ, ���Ӱ� �̵��� ����� ��Ʈ��ŷ
    //��
    backtracking(cnt + 1, upMove(board_t));//�̵� �� ī��Ʈ, ���Ӱ� �̵��� ����� ��Ʈ��ŷ
    //��
    reverse(board_t.begin(), board_t.end()); //���� �̵� �������� ���带 ���������Ƿ� �ٽ� ������
    backtracking(cnt + 1, upMove(board_t));//�̵� �� ī��Ʈ, ���Ӱ� �̵��� ����� ��Ʈ��ŷ
}

/**
 * [2048 (Easy)]
 *
 * - ��, ��, ��, ��� �̵��ϴ� ��쿡 ���� �ִ� 5�� �̵���Ű�� ��� ��츦 ���� ��, ���� ū ��� ã�� ���� - ��Ʈ��ŷ
 * - �����̴� �Լ��� �ϳ��� ¥��, ���带 �������鼭 ��, ��, ��, �� ��� ������ �������� ����
 *
 * - �� <-> ��: �� ������ ����� �ذ�
 * - ��/�� <-> ��/��: Transpose Matrix Ȱ��
 *
 * - ex. 2 2 1 �� ��, ��, ��, ��� �̵��ϴ� ��� ���ϴ� ��
 *       2 2 2
 *       4 4 4
 *  -��: ���� �迭���� ������ �����̴� �Լ� ����
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -��: ���� �迭�� �� ������ ������ ��, ������ �����̴� �Լ� ����
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -��: ���� �迭�� ��ġ ����� ���� ��, ������ �����̴� �Լ� ����
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -��: ���� �迭�� ��ġ ��Ŀ��� �� ������ ������ ��, ������ �����̴� �Լ� ����
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    //�Է�
    cin >> n; //������ ũ�� �Է�
    matrix board(n, vector<int>(n, 0)); //���� ���� �ʱ�ȭ
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //������ �ʱ� ���� �Է�
        }
    }

    //����
    backtracking(0, board); //2048 ����

    //���
    cout << ans; //���� ū ��� ���
    return 0;
}