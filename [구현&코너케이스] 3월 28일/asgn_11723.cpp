#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    set<int> a;

    cin >> m;

    while (m--) {
        string s;
        cin >> s;
        int x;

        if (s == "add") {
            cin >> x;
            if (a.find(x) == a.end())
                a.insert(x);
        }

        else if (s == "remove") {
            cin >> x;
            if (a.find(x) != a.end())
                a.erase(x);
        }

        else if (s == "check") {
            cin >> x;
            if (a.find(x) == a.end())
                cout << 0;
            else
                cout << 1;
        }

        else if (s == "toggle") {
            cin >> x;
            if (a.find(x) == a.end())
                a.insert(x);
            else
                a.erase(x);
        }

        else if (s == "all") {
            a.clear();
            for (int i = 0; i < 20; ++i)
                a.insert(i + 1);
        }

        else if (s == "empty") {
            a.clear();
        }
    }

    return 0;
}