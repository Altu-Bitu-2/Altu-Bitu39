#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll>& arr, ll fixed, int left, int right) {
    pair<ll, ll> ans; //반환할 결과값 pair
    ans = make_pair(INF, INF); //INF값으로 디폴트 설정

    while (left < right) { //두 포인터가 겹치지 않을 때까지
        ll mix = fixed + arr[left] + arr[right]; //고정값 + 두 포인터 합
        if (mix == 0) { //합이 0일 경우
            return make_pair(arr[left], arr[right]); //해당 값 반환
        }
        if (abs(mix) < min_diff) { //합의 절댓값이 최솟값보다 작을 경우
            min_diff = abs(mix); //최솟값 재설정
            ans = make_pair(arr[left], arr[right]); //ans로 설정해두기
        }
        if (mix > 0) { //합이 0보다 크면
            right--; //right를 줄여 0에 가깝게
        }
        else { //합이 0보다 작으면
            left++; //left를 올려 0에 가깝게
        }
    }
    return ans; //ans 반환
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n; //전체 용액의 수

    //입력
    cin >> n;
    vector<ll> arr(n, 0); //각 용액의 특성값 벡터
    for (int i = 0; i < n; i++) { //특성값 입력
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(), arr.end()); //특성값 정렬
    tuple<ll, ll, ll> ans; //3개짝 tuple
    for (int i = 0; i < n - 2; i++) { //처음부터 n-2까지 i 고정
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second); //새로운 값으로 출력값 설정
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans); //ans에서 get으로 출력
    return 0;
}