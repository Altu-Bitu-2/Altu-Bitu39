#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const pair<int, ci>& c1, const pair<int, ci>& c2) { //���� ���� ����
    if (c1.second.first != c2.second.first) { //��õ Ƚ���� �ٸ� ���
        return c1.second.first < c2.second.first; //��õ Ƚ�� ���� ��
    }
    return c1.second.second < c2.second.second; //��õ Ƚ�� ���� ��� ���� ������ ����
}

/**
 * [�ĺ� ��õ�ϱ�]
 *
 * 1. ����ִ� ����Ʋ�� ���� ���, ���� ��õ���� ���� �л� �� �Խ� �ð��� ������ �л��� ����
 * -> min_element() �Լ��� Ȱ���ؼ� ������ �����ϴ� �л� ã��
 * -> min_element(x.begin(), x.end(), cmp): x �����̳� ������ �ּڰ��� ã���ִ� �Լ��� ���İ� ����ϰ� cmp�Լ� �Ἥ ���� ���� ����!
 *
 * 2. �ĺ� �л��� �ٷ� ã�� ���� �� Ǯ�̴� map �����̳ʸ� ����� ����
 *
 * !����! �Խ� �ð� ���� ���� ��, �ĺ��� �ö� ���� ù �ð��� ����. �̹� �ĺ��� �ִµ� �Խ� �ð��� ���ŵ��� �ʵ��� ����.
 */

int main() {
    int n, m, input; //����Ʋ ����, ��ü ��õ Ƚ��, ��õ���� �л� ��ȣ

    //�Է� & ����
    cin >> n >> m; //����Ʋ, ��õ �� �Է�
    map<int, ci> candidate; //first: �ĺ� �л�, second: {��õ Ƚ��, �Խ� �ð�}
    for (int i = 0; i < m; i++) { //��õ �ޱ�
        cin >> input; //��õ���� �л�
        //����ִ� ����Ʋ�� ���� ���
        if (candidate.size() == n && candidate.find(input) == candidate.end()) {
            candidate.erase(min_element(candidate.begin(), candidate.end(), cmp)); //cmp�� ���� ���� ����
        }
        //ù �Խö��
        if (candidate.find(input) == candidate.end()) {
            candidate[input].second = i; //���� �Խ�
        }
        candidate[input].first++; //��õ Ƚ�� ����
    }

    //���
    for (auto iter = candidate.begin(); iter != candidate.end(); iter++) { //����Ʋ�� ����� ���� �ĺ� ���
        cout << iter->first << ' ';
    }
    return 0;
}