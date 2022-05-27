#include <iostream>
#include <string>
#include <vector>
#include <cstring>
// 포기..ㅋ ㅠㅠ 모르겠어 
using namespace std;

int solution(vector<vector<int>> beverage, int p) {
    int answer = 0;
    int n = beverage.size();

    int dp[40][30]; // first: i번째 음료수까지 사용해서, second: j 양을 맞췄을 때 최대 칼로리 
    memset(dp, 0, sizeof(dp));
    vector<vector<vector<int>>> amounts(40); // dp[i][j]를 맞추고 현재 갖고 있는 음료의 개수 
    vector<int> idx0amount;

    for (auto b : beverage) {
        idx0amount.push_back(b[0]);
    }
    amounts[0][0] = idx0amount;

    for (int i = 0; i < n; i++) {
        int num = beverage[i][0];
        int amount = beverage[i][1];
        int kcal = beverage[i][2];

        for (int j = 1; j <= p; j++) { // 맞춰야하는 음료의 양 
            if (i == 0) {
                if (j < amount) {
                    
                    dp[i][j] = 0; // 아무 음료도 
                }
            } else {
                vector<int> vec = amounts[i-1][j]; // 특정 상태의 음료 개수 
                

            }
            
        }
    }


    return answer;
}