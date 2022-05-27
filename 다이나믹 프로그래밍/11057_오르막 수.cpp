#include <iostream>
#include <cstring>
using namespace std;

#define mod 10007

int main() {
    int n;
    cin >> n;

    int ans = 0;
  
    int dp[1005][15];
    memset(dp, 0, sizeof(dp));
    // dp[i][j] = i개의 자리 숫자에서 j로 끝나는 경우의 수 
    // ex) dp[1][0] = 1개의 자리로 이루어져있으면서 0으로 끝나는 오르막 수의 개수 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i == 1 || j == 0) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    for (int i = 0; i <= 9; i++) {
        ans += (dp[n][i] % mod);
    }
    cout << ans % mod;
    return 0;
}