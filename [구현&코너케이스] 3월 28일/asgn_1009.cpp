#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b;

    cin >> t;

    while (t--) {
        cin >> a >> b;
        long long p = pow(a, b);
        if (p % 10 == 0)
            cout << 10;
        else
            cout << p % 10;
    }

    return 0;
}