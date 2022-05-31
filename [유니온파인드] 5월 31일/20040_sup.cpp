#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //값이 음수라면 루트 정점이므로
        return node; //그대로 반환
    }
    return parent[node] = findParent(parent[node]); //계속 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //x의 루트 정점 찾기
    int yp = findParent(y); //y의 루트 정점 찾기

    if (xp == yp) { //루트 정점이 같다면
        return false; //false 반환(union 불가능, 사이클 만들어짐)
    }
    if (parent[xp] < parent[yp]) { //xp의 부모가 더 작다면
        parent[xp] += parent[yp]; //xp의 부모에 값을 더하고(크기)
        parent[yp] = xp; //xp를 yp의 새로운 루트로
    }
    else { //그렇지 않다면
        parent[yp] += parent[xp]; //yp의 부모에 값을 더하고(크기)
        parent[xp] = yp; //yp를 xp의 새로운 루트로
    }
    return true; //union 및 현 단계 사이클 x
}

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() {
    int n, m, x, y; //점의 개수, 진행된 차례의 수, 두 점

    //입력
    cin >> n >> m; //점 개수, 차례 수 입력
    parent.assign(n, -1); //각 점의 수만큼 만들어 -1로 초기화
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //두 점 입력

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클이 생성됨
            cout << i + 1; //해당 차례 출력
            return 0;
        }
    }
    cout << 0; //사이클이 생성되지 않은 경우 0 출력하고 끝냄
    return 0;
}