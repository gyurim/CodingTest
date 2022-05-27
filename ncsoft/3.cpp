#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

// 냅색 알고리즘 (DP)

int solution(vector<vector<int>> beverage, int p) {
    int answer = 0;
    int n = beverage.size();
    int dp[40][30];
    memset(dp, 0, sizeof(dp));
    vector<vector<int>> amounts(31); // 현재 남은 음료의 개수 

    for (int i = 0; i < n; i++) {
        int num = beverage[i][0]; // 음료 개수 
        int amount = beverage[i][1]; // 음료 양 
        int kcal = beverage[i][2]; // 음료의 칼로리 

        for (int j = 1; j <= p; j++) {
            if (num > 0 && j >= amount) {
                if (i == 0) {
                    if (kcal > dp[i][j-amount] + kcal) {
                        dp[i][j] = kcal;
                        
                    } else {
                        dp[i][j] = dp[i][j-amount] + kcal;
                        beverage[i][0] -= 1;
                    }
                }
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-amount] + kcal);
                // 음료의 개수 줄여주기 
                beverage[i][0] -= 1;
            } else {
                dp[i][j] = dp[i-1][j]; // i번째 음료는 마시지 않음 
            }
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
    answer = dp[n-1][p];
    return answer;
} 

int main() {
    vector<vector<int>> beverage {{2, 1, 2}, {4, 1, 11}};
    cout << solution(beverage, 5);
    return 0;
}