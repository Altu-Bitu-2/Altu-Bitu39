#include <iostream>

using namespace std;

bool isCpp(string str) { //c++ �����ΰ�?
    for (int i = 0; i < str.size(); i++) { //��Ʈ�� �� ���ھ� ������ ��
        if (isupper(str[i])) { //�빮�ڰ� ������
            return false; //false
        }
        if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) { //ù or ������ ���ڰ� '_' �Ǵ� '_'�� ���� �����ϸ�
            return false; //false
        }
    }
    return true; //������ ��� true ��ȯ
}

bool isJava(string str) { //java �����ΰ�?
    return !isupper(str[0]) && str.find('_') == string::npos; //ù ���ڰ� �빮�ڰų�, '_'�� ������ �ȵ�
}

string toCpp(string str) { //java ������ c++��
    string result; //��ȯ�� ��
    for (int i = 0; i < str.size(); i++) { //��Ʈ�� �� ���ھ� ����
        if (isupper(str[i])) { //�빮�ڶ��
            result += '_'; //'_' �ֱ�
        }
        result += tolower(str[i]); //�ҹ��ڷ� �ٲٱ�
    }
    return result; //��ȯ�� �� ��ȯ
}

string toJava(string str) { //c++ ������ java��
    string result; //��ȯ�� ��
    for (int i = 0; i < str.size(); i++) { //��Ʈ�� �� ���ھ� ����
        if (str[i] == '_') { //'_' ���
            result += toupper(str[i + 1]); //���� ���� �빮�ڷ� �ٲٱ�
            i++; //'_'�� �־����Ƿ� ���� �� ����
            continue; //���� ����
        }
        result += str[i]; //������ ���ڴ� �׳� ����
    }
    return result; //��ȯ�� �� ��ȯ
}

/**
 * [Java vs C++]
 *
 * 1. �Է����� �־��� ������ C++ ���Ŀ��� �°�, JAVA ���Ŀ��� ���� �� ���� (ex. name)
 * 2. "Error!"�� ��� (C++)
 *    2-1. �����('_')�� �����ϰų�, ������ ����
 *    2-2. �����('_')�� �����ؼ� �����ϴ� ����
 *    2-3. �빮�ڰ� �����ϴ� ����
 * 3. "Error!"�� ��� (Java)
 *    3-1. �빮�ڷ� �����ϴ� ����
 *    3-2. �����('_')�� �����ϴ� ����
 */

int main() {
    string str; //������

    cin >> str; //������ �Է�
    bool is_cpp = isCpp(str); //�������� cpp����
    bool is_java = isJava(str); //�������� java����

    if (is_cpp && is_java) { //�� ���Ŀ� ��� �����ϸ�
        cout << str; //�״�� ���
    }
    else if (is_cpp) { //c++ �����̶��
        cout << toJava(str); //java�� �ٲ� ���
    }
    else if (is_java) { //java �����̶��
        cout << toCpp(str); //cpp�� �ٲ� ���
    }
    else { //�� �� �ƴ϶��
        cout << "Error!"; //���� �޼��� ���
    }
    return 0;
}