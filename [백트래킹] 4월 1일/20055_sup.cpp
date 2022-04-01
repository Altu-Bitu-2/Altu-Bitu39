#include <iostream>
#include <vector>

using namespace std;

struct info { //�������� �κ� ���� ����
    int power;
    bool is_on;
};

vector<info> belt;  //�����̳� ��Ʈ ����(������, �κ� ����)
int zero_power;     //�������� 0�� ��Ʈ ĭ�� ����

int minusPosition(int n, int pos) { //�ε��� ����(��Ʈ ȸ��)
    if (--pos >= 0) {
        return pos;
    }
    return n * 2 - 1; //��ġ�� 0�� ���
}

void second(int n, int start, int end) {
    int cur = end;
    while (cur != start) { //end - 1 ���� start ���� �˻�
        cur = minusPosition(n, cur);
        int next = (cur + 1) % (n * 2); //���� ��ġ
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //���� ��ġ�� �κ��� �ְ�, ���� ��ġ�� �κ��� ������ ������ 1�̻��� ��� -> �κ� �ű�
            belt[cur].is_on = false; //�� ��ġ �κ�x
            belt[next].power--; //���� ��ġ ������ -1
            if (next != end) { //������ ��ġ �ƴ� ��츸
                belt[next].is_on = true; //�κ� �ű��
            }
            if (belt[next].power == 0) { //�������� 0�̶�� ���� ���� ++
                zero_power++;
            }
        }
    }
}

void third(int start) {
    if (belt[start].power) { //�ø��� ��ġ�� �������� 0�� �ƴ϶�� �κ� �ø�
        belt[start].is_on = true; //�κ� �ø���
        belt[start].power--; //������ --
        if (belt[start].power == 0) { //������ 0�̶�� ���� ���� ++
            zero_power++;
        }
    }
}

/**
 * [�����̾� ��Ʈ ���� �κ� ����]
 * 1. ��Ʈ�� �� ĭ ���� �κ��� �Բ� �� ĭ ȸ��
 * 2. ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ ȸ�� �������� �� ĭ �̵��� �� �ִٸ� �̵� (�̵�����: �̵��Ϸ��� ĭ�� �κ��� ����, �� ĭ�� �������� 1 �̻��̾�� ��)
 * 3. �ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ� �ø�
 * 4. �������� 0�� ĭ�� ������ k�� �̻��̶�� ���� ����. �׷��� �ʴٸ� 1�� ���ư�
 * -> 1 ~ 3������ 1�ܰ�
 *
 * [���� Ǯ��]
 * ��Ʈ�� �κ��� �ű�� �� �ƴ϶�, �ø��� ��ġ�� ������ ��ġ�� �ε��� ���� �ٲ㼭 ����
 * �ʿ��� �����̳�: �������� �κ��� ���翩�θ� üũ�� �迭
 *
 * 1��: ��Ʈ�� ������ �������̹Ƿ�, ��Ʈ �� ĭ ȸ�� �� �ø��� ��ġ�� ������ ��ġ�� �ε��� ���� �ϳ� ����
 * 2��: ���� ���� �ö� �κ����� ����ؾ� �ϹǷ� (������ ��ġ - 1)���� (�ø��� ��ġ)���� �˻� -> �κ� �ű�� �� �����ϸ� ���翩�� üũ�ϰ� ������ ����
 * 3��: �ø��� ��ġ ĭ ������ 0�� �ƴ϶�� �ش� ĭ �κ� ���� ���� üũ + ������ ����
 *
 * �ش� ������ deque �ڷᱸ���� ����ؼ��� ���� ���� (1������ ȸ���ϴ� �κи� �ٸ��� 2��, 3���� ������ ����)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    //�Է�
    cin >> n >> k; //��ü ĭ ��, ���� ���� ĭ �� �Է�
    belt.assign(n * 2, { 0, false }); //��Ʈ ������ ����
    for (int i = 0; i < n * 2; i++) { //�� ĭ�� ������ �Է�
        cin >> belt[i].power;
    }

    //����
    int start = 0;    //�ø��� ��ġ
    int end = n - 1;  //������ ��ġ
    int step = 0;     //�ܰ� ��
    while (true) {
        start = minusPosition(n, start); //��Ʈ ȸ�� -> �ø��� ��ġ
        end = minusPosition(n, end); //��Ʈ ȸ�� -> ������ ��ġ
        if (belt[end].is_on) { //��Ʈ ȸ�� ��, �κ��� ������ ��ġ�� �ִٸ� ������
            belt[end].is_on = false;
        }
        second(n, start, end); //�κ� �̵�
        third(start); //�κ� �ø���
        step++; //�ܰ�++
        if (zero_power >= k) { //���� ����(������ 0�� ĭ ��)
            break;
        }
    }

    //���
    cout << step; //�ܰ� ���
    return 0;
}