#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 아 ㅠㅠㅠ 어려워 ㅠㅠㅠ 머리가 꼬임.. 휴 
int main() {
    vector<int> cards;
    int n, card;
    cin >> n;
    int max = 0, maxIdx = -1;

    int odd_sum[50005] = {0};
    int even_sum[50005] = {0};

    for (int i = 1; i <= n; i++) {
        cin >> card;
        cards.push_back(card);

        if (i % 2 == 1) {
            odd_sum[i/2 + 1] = odd_sum[i/2] + card;
        } else {
            even_sum[i/2] = even_sum[i/2 - 1] + card;
        }
    }

    // dp 
    int dp[100001];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) { 
            dp[i] = odd_sum[i/2] + (even_sum[n/2] -  even_sum[i/2]);
        } else {
            dp[i] = odd_sum[i/2] + (even_sum[n/2 - 1] - even_sum[i/2 - 1]);
        }
    }
    int answer = dp[1];

    for (int i = 1; i <= n; i++) {
        answer = (answer <= dp[i]) ? dp[i] : answer;
    }
    cout << answer;
    return 0;
}