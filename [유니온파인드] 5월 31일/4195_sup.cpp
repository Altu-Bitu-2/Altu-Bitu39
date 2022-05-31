#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //친구 관계가 모두 다른 사용자로 들어왔을 때의 정점 최댓값

vector<int> parent(MAX + 1, -1);
map<string, int> people;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //음수이면
        return node; //루트 정점이므로 그대로 반환
    }
    return parent[node] = findParent(parent[node]); //계속 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모 찾기
    int yp = findParent(y); //y의 부모 찾기

    if (xp == yp) { //각 루트 정점이 같다면
        return; //이미 같은 집합이므로 유니온 x
    }
    if (parent[xp] < parent[yp]) { //yp의 부모가 더 크다면
        parent[xp] += parent[yp]; //xp의 부모에 yp의 부모 값 더하고
        parent[yp] = xp; //xp를 새로운 루트로
    }
    else { //그렇지 않다면
        parent[yp] += parent[xp]; //yp의 부모에 xp의 부모 값 더하고
        parent[xp] = yp; //yp를 새로운 루트로
    }
}

/**
 * [친구 네트워크]
 *
 * 1. weighted union find -> 루트 정점에 친구의 수(집합 원소 수) 저장
 * 2. 친구 네트워크에 몇 명 있는지 구하기 -> 루트 정점의 parent값 접근
 *
 * !주의! 정점이 문자열로 들어오므로 map을 활용해 string을 int로 매핑
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, f; //테스트 케이스 개수, 친구 관계 수
    string a, b; //두 사용자 아이디

    //입력
    cin >> t; //테스트 케이스 수 입력
    while (t--) { //전부 테스트
        int idx = 1; //정점과 매핑할 수
        parent.assign(MAX + 1, -1); //-1로 초기화

        cin >> f; //친구 관계 수 입력
        while (f--) { //친구 관계 계산하기
            cin >> a >> b; //두 사용자 아이디
            if (!people[a]) { //맵에 a의 사용자 아이디가 없다면
                people[a] = idx++; //int로 매핑
            }
            if (!people[b]) { //맵에 a의 사용자 아이디가 없다면
                people[b] = idx++; //int로 매핑
            }

            //연산
            int x = people[a], y = people[b]; //매핑한 수 x, y에 저장
            unionInput(x, y); //유니온

            //출력
            cout << -parent[findParent(x)] << '\n'; //집합의 크기를 이용해 출력
        }
    }
    return 0;
}