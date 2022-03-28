#include <iostream>

using namespace std;

int main() {
    int t, a, b;

    cin >> t;

    while (t--) {
        int p = 1;
        cin >> a >> b;
        while (b--) {
            p = (p * a) % 10;
            if (p == 0)
                break;
        }
        if (p == 0)
            cout << 10 << '\n';
        else
            cout << p << '\n';
    }

    return 0;
}
