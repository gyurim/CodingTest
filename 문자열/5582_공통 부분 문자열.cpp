#include <iostream>
#include <cstring>

using namespace std;
int dp[4005][4005];

int main() {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    
    // 시간초과 해결 
    // 시간복잡도: O(m) * O(n) 
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) dp[i][j] = 1;
        }
    }

    int min_n = min(s.length(), t.length());

    for (int i = 1; i < s.length(); i++) {
        for (int j = 1; j < t.length(); j++){
            if (s[i] == t[j])
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
        }
    }

    // 두 문자열 사이 가장 긴 부분 문자열을 구하기 
    // 시간 초과 
    // 시간복잡도: s의 부분집합 O(m*2) * t에 s의 부분집합이 존재하는지 확인 O(n) => O(m*2 * n)
    // int next_idx = 0;
    // for (int i = 0; i < s.length();) {
    //     int idx = t.find(s[i], next_idx);
    //     if (idx == string::npos) {
    //         i++;
    //         next_idx = 0;
    //     }
    //     else {
    //         int cnt = 0;
    //         bool isEnd = false;
    //         while (s[i + cnt] == t[idx + cnt]) {
    //             cnt++;
    //             if (i + cnt >= s.length() || idx + cnt >= t.length()) {
    //                 isEnd = true;
    //                 break;
    //             }
    //         }
    //         ans = max(cnt, ans);

    //         if (isEnd) break;
    //         next_idx = idx + 1;
    //     }
    // }
    cout << ans;
    return 0;
}