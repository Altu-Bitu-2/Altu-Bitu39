#include <iostream>

using namespace std;

struct node_info {
    int data; //��� ��
    node_info* left; //���� ����Ʈ��
    node_info* right; //������ ����Ʈ��
};

node_info* makeTree(node_info* node, int data) {
    if (node == NULL) { //�̹� ��尡 ���Ե� ��ġ
        node = new node_info(); //���� �Ҵ�
        node->data = data; //��� ��
        node->left = node->right = NULL; //����, ������ ����Ʈ�� NULL�� �ʱ�ȭ
    }
    else if (node->data > data) { //�θ� ��Ʈ�� Ű���� �۴ٸ�
        node->left = makeTree(node->left, data); //���� ����Ʈ����
    }
    else if (node->data < data) { //�θ� ����� Ű���� ũ�ٸ�
        node->right = makeTree(node->right, data); //������ ����Ʈ����
    }
    return node; //��� ����
}

//���� ��ȸ
void postorder(node_info* node) {
    if (node == NULL) { //��尡 ����ٸ�
        return; //��ȯ
    }
    postorder(node->left); //���� ������
    postorder(node->right); //������ ������
    cout << node->data << '\n'; //��Ʈ ���
}

/**
 * �ʰ� �� PPT �� BST ��� ���� ���� ����
 *
 * [���� �˻� Ʈ��]
 *
 * 1. �����ͷ� ����, ������ ����Ʈ���� ����Ű�� ����ü ����
 * 2. NULL ���� ������ ���ǿ� ���� ���� �Ǵ� ���������� �̵�
 * 3. ��尡 �� ��ġ�� ã���� �����Ҵ� �� ��� �����
 * 4. �ϼ��� Ʈ���� ���� ��ȸ
 */

int main() {
    int input; //���� �ֱ� ���� input ����

    //�Է� & ����
    node_info* root = NULL; //Ʈ�� ����ü
    while (cin >> input) { //���� �Է�
        root = makeTree(root, input); //Ʈ�� �����
    }

    //�ⷰ
    postorder(root); //���� ��ȸ ���
    return 0;
}