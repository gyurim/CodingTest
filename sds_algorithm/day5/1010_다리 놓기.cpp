#include <iostream>
using namespace std;

int n, m;

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        int dif = (n < m - n) ? m - n : n;
        long long ans = 1;

        for (int i = dif + 1; i <= m; i++) {
            ans *= i;
        }

        for (int i = 2; i <= m - dif; i++) {
            ans /= i;
        }

        cout << ans << '\n';
    }
    return 0;
}