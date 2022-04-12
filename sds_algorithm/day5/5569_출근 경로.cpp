#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MOD 100000
// 모르겠음. 조합(파스칼의 삼각형)으로 푸는 방법은 없나? 

int main() {
    int w, h;
    cin >> w >> h;
    int dp[101][101];
    fill(&dp[0][0], &dp[101][101], 1);

    dp[2][2] = 0; 
    dp[2][1] = 2;
    dp[1][2] = 2;

    for (int i = 2; i <= w; i++) {
        for (int j = 2; j <= h; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[w][h] % MOD;
    return 0;
}