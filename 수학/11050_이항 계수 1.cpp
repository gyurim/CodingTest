#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int m = n - k;
    int sum = 1;
    for (int i = k+1; i <= n; i++) {
        sum *= i;
    }
    for (int i = 2; i <= m; i++) {
        sum /= i;
    }
    cout << sum;
    return 0;
}