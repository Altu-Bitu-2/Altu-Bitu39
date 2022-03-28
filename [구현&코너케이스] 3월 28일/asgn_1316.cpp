#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int cnt = 0;

    cin >> n;

    while (n--) {
        int i = 0;
        string s;
        cin >> s;
        vector<int> a;
        a.assign(100, 0);

        a[i] = s[0];
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] != a[i]) {
                ++i;
                a[i] = s[j];
            }
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        if (a.size() - 2 == i)
            cnt++;
    }

    cout << cnt;

    return 0;
}