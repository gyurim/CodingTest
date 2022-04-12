#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100005

int main() {
    int n, k;
    cin >> n >> k;
    int v[101];
    int w[101];
    
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    // 2차원 배열.ver
    /*
    int dp[105][MAX];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= w[i]) {
                // max(i번째 물건 안 넣기,i번째 물건 넣기)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            } else 
                dp[i][j] = dp[i-1][j]; // i번째 물건은 배낭에 넣지 않음 
        }
    }
    cout << dp[n][k];
    */
    // 1차원 배열.ver
    int dp[MAX];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 1; j--) {
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[k];
    return 0;
}