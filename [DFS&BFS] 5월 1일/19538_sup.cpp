#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>& people, vector<int>& init, int n) {
    vector<int> rest(n + 1, 0); //각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q; //bfs 계산 위한 큐

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0; //최초 유포자는 0분에 믿음
        q.push(init[i]); //bfx 계산 위해 큐에 넣기
    }

    //루머 믿어야 하는 주변인 수 초기화
    for (int i = 1; i <= n; i++) { //각 사람마다 최소 주변인 수 계산
        rest[i] = (people[i].size() + 1) / 2;
    }

    while (!q.empty()) {
        int curr = q.front(); //현재 사람
        int t = ans[curr]; //루머 믿은 시간
        q.pop(); //계산한 사람은 큐에서 삭제

        for (int i = 0; i < people[curr].size(); i++) {
            int next = people[curr][i]; //현재 사람의 다음 사람
            if (ans[next] > -1) { //이미 루머를 믿는다면
                continue; //스킵
            }
            rest[next]--; //최소 주변인 수 줄어듦
            if (!rest[next]) { //주변인들 중 절반 이상이 루머를 믿으면(수가 줄어 0이 되었다면)
                ans[next] = t + 1; //믿은 시간에 +1
                q.push(next); //다음 사람의 다음 사람을 계산하기 위해 큐에 넣기
            }
        }
    }
    return ans;
}

/**
 * [루머]
 *
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크 배열을 루머를 믿는 시간을 저장하는 배열로 대체함
 *    ans[i] = -1 일 경우, i는 루머를 믿지 않는다
 *    ans[i] = t인 경우, i는 t분 부터 루머를 믿기 시작함
 * 각자가 루머를 믿기 위해 주변인의 절반 이상이 루머를 믿어야 하므로, 각 사람이 루머를 믿기까지 루머를 믿는 주변인 몇명이 남았는지를 리스트에 기록한다.
 * 남은 사람이 0인 순간, 해당 사람은 루머를 믿기 시작
 */

int main() {
    int n, m, input; //사람의 수, 최초 유포자 수, 주변인 파악 위한 input

    //루머 퍼뜨리는 관계 입력
    cin >> n; //사람 수 입력
    vector<vector<int>> people(n + 1, vector<int>()); //주변인 관계 벡터
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> input; //input 입력
            if (!input) { //0 입력 시 주변인 입력 중지
                break;
            }
            people[i].push_back(input); //i번째 사람의 주변인으로 넣기
        }
    }

    //최초 유포자 입력
    cin >> m; //최초 유포자 수 입력
    vector<int> init(m, 0); //최초 유포자 벡터
    for (int i = 0; i < m; i++) { //최초 유포자 번호 입력
        cin >> init[i];
    }

    //연산
    vector<int> ans = bfs(people, init, n); //모든 사람이 루머를 믿기 시작하는 시간 계산

    //출력
    for (int i = 1; i <= n; i++) { //각 사람마다 걸리는 시간 출력
        cout << ans[i] << ' ';
    }
    return 0;
}