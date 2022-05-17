#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

//������ ���� ������ ��ȿ���� Ȯ��
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE && board[r][c] == stone; //�ٵ��� ���� �ִ���, �� ������ �´��� Ȯ��
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) {
    //����, ����, ������ �밢��, ����� �밢��
    int dr[4] = { 0, 1, 1, -1 }; //���� ���⿡ ���� Ȯ���� ���� ��ǥ
    int dc[4] = { 1, 0, 1, 1 }; //���� ���⿡ ���� Ȯ���� ���� ��ǥ

    //(r, c) ������ ��ġ�� �̾����� ���� �ֳ�?
    if (promising(r - dr[d], c - dc[d], stone, board)) { //���� ��ġ �� Ȯ��
        return false; //�ִٸ� false
    }
    int cnt = 0; //ī��Ʈ �ʱ�ȭ
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)�� ���� �������� �ϴ� �̾����� �ٵϾ��� ����
        cnt++; //5���� �̾������� Ȯ���ϱ� ���� ī��Ʈ
        r += dr[d]; //�������� �̾����� ��ǥ
        c += dc[d]; //�������� �̾����� ��ǥ
    }
    return cnt == 5; //5���� �̾����� �� �´ٸ� true
}

bool isEnd(int r, int c, vector<vector<int>>& board) {
    for (int i = 0; i < 4; i++) { //����, ����, ������ �밢��, ����� �밢��
        if (validDir(r, c, i, board[r][c], board)) { //������ �̷���� �¸��ߴٸ�
            return true; //true ��ȯ
        }
    }
    return false; //������ ��������� �ʾҴٸ� false ��ȯ
}

/**
 * [����]
 *
 * 1. Ư�� ��ǥ(r, c)�� ���� �������� �ϴ� ������ ��� ���� ��ġ�� ���� ���� ���� Ȯ��
 *    ������ ��� ��ġ :  ������, �Ʒ�, ������, �����
 * 2. (����) �����̻��� �Ǵ��� Ȯ���ؾ� ��
 *
 */

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); //�ٵ��� ����

    //�Է�
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j]; //�ٵ��� �� �ٵϾ� ��Ȳ �Է�
        }
    }

    //���� & ���
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) { //���� ����
                continue; //�̾ ���
            }
            if (isEnd(i, j, board)) { //������ �̰峪?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; //�̱� �ٵϾ� ��, ������ ��ȣ, ������ ��ȣ ���
                return 0; //0 ��ȯ�� ������
            }
        }
    }
    cout << 0; //�ºΰ� �������� ���� ��� 0 ����� ������
    return 0;
}