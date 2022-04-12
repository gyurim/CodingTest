#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    int num;
    long long dp[21][101];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    dp[nums[0]][0] = 1;

    for (int i = 1; i < n-1; i++) {
        for (int j = 0; j <= 20; j++) {
            long long cnt = dp[j][i-1];
            if (cnt > 0) {
                if (j + nums[i] <= 20) {
                    int nxt = j + nums[i];
                    dp[nxt][i] += cnt;
                }
                if (j - nums[i] >= 0) {
                    int nxt = j - nums[i];
                    dp[nxt][i] += cnt;
                }
            }
        }
    }
    cout << dp[nums[n-1]][n-2];

    return 0;
}
// ---------------- 백트레킹 풀이 -> 시간초과 ----------------
// vector<int> nums;
// int total = 0;
// int n, ans = 0;

// void backtracking(int sum, int cnt){
//     if (cnt == n-2) {
//         if (sum == total){
//              ans++;
//         }
//         return;
//     }
//     if (sum < 0 || sum > 20) return;
    
//     backtracking(sum + nums[cnt+1], cnt+1);
//     backtracking(sum - nums[cnt+1], cnt+1); 
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n;
//     int num;
//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         nums.push_back(num);
//         if (i == n-1)
//             total = num;
//     }
//     backtracking(nums[0], 0);
//     cout << ans;
//     return 0;
// }