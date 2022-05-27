#include <string>
#include <vector>
#include <cstring>
#include <iostream>

// 편집 거리 알고리즘 (DP)

using namespace std;

int dp[10001][10001];

void init(string p, string s) {
    memset(dp, 0, sizeof(dp));
    int maxLength = max(p.length(), s.length());
    for (int i = 1; i <= maxLength; i++) {
        dp[i][0] = i;
        dp[0][i] = i;
    }
}

bool canEdit(string p, string s) {
    int p_zero = 0, p_one = 0;
    int s_zero = 0, s_one = 0;

    for (auto c : p) {
        if (c == '0') p_zero++;
        else p_one++;
    }

    for (auto c : s) {
        if (c == '0') s_zero++;
        else s_one++;
    }
    
    if (p_zero > s_zero || p_one > s_one) return false; // s의 삭제로 p를 만들 수 없음 
    return true;
}

int solution(string p, string s) {
    int answer = -1;

    string cpyP = p;
    int minCnt = 98765421;

    while(true) {
        init(p, s);
        // s.length() > p.length()
        // s의 문자를 삭제해서 p와 같게 만들어야함 
        if (!canEdit(p, s)) {
            minCnt = -1;
            break;
        }
        
        for (int i = 1; i <= p.length(); i++) {
            for (int j = 1; j <= s.length(); j++) {
                if (p[i-1] == s[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else {
                    // p: st 와 s: str 가 다른 경우, dp[2][3] = dp[2][2] + 1
                    dp[i][j] = dp[i][j-1] + 1;
                }
            }
        }
        int cnt = dp[p.length()][s.length()];
        minCnt = min(minCnt, cnt);
        p += cpyP;
        if (p.length() > s.length()) break;
    }
    answer = minCnt;
    cout << answer;
    return answer;
}

int main() {
    solution("00", "1111");
    return 0;
}