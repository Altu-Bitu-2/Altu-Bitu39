#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x;
    vector<int> a(20);

    cin >> m;

    while (m--) {
        string s;
        cin >> s;

        if (s == "all") {
            a.assign(20, true);
            continue;
        }

        else if (s == "empty") {
            a.assign(20, false);
            continue;
        }

        cin >> x;

        if (s == "add") {
            if (!a[x - 1])
                a[x - 1] = true;
        }

        else if (s == "remove") {
            if (a[x - 1])
                a[x - 1] = false;
        }

        else if (s == "check") {
            cout << a[x - 1] << '\n';
        }

        else if (s == "toggle") {
            if (a[x - 1])
                a[x - 1] = false;
            else
                a[x - 1] = true;
        }
    }

    return 0;
}
