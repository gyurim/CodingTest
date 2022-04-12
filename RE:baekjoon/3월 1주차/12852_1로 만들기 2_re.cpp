#include <iostream>
using namespace std;

#define MAX 1000005

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    int dp[MAX];
    int num[MAX];

    dp[1] = 0;
    num[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        num[i] = i-1;
        if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            num[i] = i/3; 
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            num[i] = i/2;
        }
    }  
    cout << dp[n] << "\n";

    while(n >= 1) {
        cout << n << " ";
        n = num[n];
    }

    return 0;
}