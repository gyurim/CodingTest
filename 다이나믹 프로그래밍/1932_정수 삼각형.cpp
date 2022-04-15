// 2022.04.15 

#include <iostream>
#include <cstring> // memset 
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[501][501] = {0};
    int dp[501][501];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];

            if (i == 1) {
                dp[i][j] = arr[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        max = (max <= dp[n][i]) ? dp[n][i] : max;
    }

    cout << max;
    return 0;
}