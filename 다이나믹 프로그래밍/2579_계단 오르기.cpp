#include <iostream>
#include <algorithm>
using namespace std;

int stairs[305] = {0};
int total[305] = {0};

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    if (n >= 1) {
        total[1] = stairs[1];
    }
    if (n >= 2) {
        total[2] = total[1] + stairs[2];
    }
    if (n >= 3) {
        total[3] = stairs[3] + max(stairs[1], stairs[2]);
    }
    if (n >= 4) {
        for (int i = 4; i <= n; i++) {
            total[i] = max(total[i-2], total[i-3] + stairs[i-1]) + stairs[i];
        }
    }

    cout << total[n];

    return 0;
}