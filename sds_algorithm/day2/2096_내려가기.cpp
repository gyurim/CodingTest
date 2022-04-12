#include <iostream> 
#include <algorithm>
using namespace std;

int max_dp[4];
int min_dp[4];

// max_dp, min_dp는 현재 입력받은 위치의 숫자와 

int main() {
    int n;
    cin >> n;
    int a, b, c;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        if (i == 0) {
            max_dp[0] = a; 
            max_dp[1] = b;
            max_dp[2] = c;

            min_dp[0] = a; 
            min_dp[1] = b;
            min_dp[2] = c;
        } else {
            int _a = max_dp[0];
            int _b = max_dp[1];
            max_dp[0] = a + max(max_dp[0], max_dp[1]);
            max_dp[1] = b + max(_a, max(max_dp[1], max_dp[2]));
            max_dp[2] = c + max(_b, max_dp[2]);

            _a = min_dp[0];
            _b = min_dp[1];
            min_dp[0] = a + min(min_dp[0], min_dp[1]);
            min_dp[1] = b + min(_a, min(min_dp[1], min_dp[2]));
            min_dp[2] = c + min(_b, min_dp[2]);
        }
    }

    cout << max(max_dp[0], max(max_dp[1], max_dp[2])) << " ";
    cout << min(min_dp[0], min(min_dp[1], min_dp[2]));

    return 0;
}