#include <iostream>
#include <string.h>

using namespace std;

int d[12];

void dp(int n) {
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i <= n; i++) {
        if (d[i] == -1) {
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int num;

    memset(d, -1, sizeof(d));
    for (int i = 0; i < t; i++) {
        cin >> num;
        dp(num);
        cout << d[num] << "\n";
    }
    return 0;
}