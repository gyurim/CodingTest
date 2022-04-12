#include <iostream>
using namespace std;

int dp[1001];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int c;
    cin >> c;
    int n;

    dp[1] = 3;
    int idx = 1;

    while(c--) {
        cin >> n;
        // x와 y가 서로소 관계여야한다. (최대공약수 == 1)
        
        if (dp[n] != 0) 
            cout << dp[n] << '\n';
        else {
            while (idx <= n) {
                int i = 1;
                dp[idx+1] = dp[idx];
                while (i < idx + 1) {
                    if (gcd(i, idx + 1) == 1) dp[idx+1]++;
                    i++;
                }
                while (i > 1) {
                    i--;
                    if (gcd(idx + 1, i) == 1) dp[idx+1]++;  
                }
                idx++;
            }
            cout << dp[n] << '\n';
        }
    }
    return 0;
}