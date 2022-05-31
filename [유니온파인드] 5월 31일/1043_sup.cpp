#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //부모가 음수라면
        return node; //루트 정점이므로 그대로 반환
    }
    return parent[node] = findParent(parent[node]); //계속 부모 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //부모가 같다면
        return; //이미 같은 집합에 있음
    }
    if (parent[xp] < parent[yp]) { //yp의 부모가 더 크다면
        parent[xp] += parent[yp]; //xp의 부모에 값을 더하고(크기)
        parent[yp] = xp; //xp를 yp의 새로운 루트로
    }
    else { //그렇지 않다면
        parent[yp] += parent[xp]; //yp의 부모에 값을 더하고(크기)
        parent[xp] = yp; //yp를 xp의 새로운 루트로
    }
}

int liarParty(vector<int>& parties) {
    int cnt = 0; //거짓말할 파티 카운트 초기화
    for (int i = 0; i < parties.size(); i++) { //각 파티
        if (findParent(parties[i]) != findParent(0)) { //해당 파티의 루트가 0들의 집합이 아닌 경우
            cnt++; //거짓말 가능
        }
    }
    return cnt; //카운트 반환
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

int main() {
    int n, m; //사람의 수, 파티의 수

    //입력
    cin >> n >> m; //사람, 파티 수 입력
    parent.assign(n + 1, -1); //-1로 초기화

    int init, p; //진실을 아는 사람의 수, 번호
    cin >> init; //진실을 아는 사람 수 입력
    while (init--) { //진실을 아는 사람들
        cin >> p; //진실을 아는 사람의 번호 입력
        unionInput(0, p); //진실을 아는 사람의 루트 정점을 0으로 설정
    }

    int cnt, first_person, person; //각 파티에 오는 사람의 수, 번호들
    vector<int> parties; //파티 벡터
    while (m--) { //모든 파티 계산할 동안
        cin >> cnt >> first_person; //파티 사람 수, 첫 번호

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) { //모든 사람 계산할 동안
            cin >> person; //다른 번호들 입력
            unionInput(first_person, person); //각 파티의 집합 만들기
        }
    }

    //연산 & 출력
    cout << liarParty(parties); //거짓말 가능한 파티 수 계산해 출력
    return 0;
}