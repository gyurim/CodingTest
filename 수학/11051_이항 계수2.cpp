#include <iostream>
using namespace std;

long long c[1001][1001] = {0};

int main() {
    int n, k;
    cin >> n >> k;

    // nCk = n-1 C k-1 + n-1 C k
    for (int i = 1; i <= n; i++) {
        c[i][1] = i % 10007;
        c[i][i] = 1;
        c[i][0] = 1; // 이거 안 넣어서 틀렸음
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            if (j > k) break;
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % 10007;
        }
    }
    cout << c[n][k];
    
    return 0;
}