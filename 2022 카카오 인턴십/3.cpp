#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int dp[200][200]; // [alp][cop] = 해당 power를 만족하는 최단 시간 
    int n = problems.size();

    int alp_max_req = 0;
    int cop_max_req = 0;

    for (auto problem : problems) {
        int alp_req = problem[0];
        int cop_req = problem[1];

        alp_max_req = max(alp_max_req, alp_req);
        cop_max_req = max(cop_max_req, cop_req);
    }

    dp[alp][cop] = 0;
    if (alp == 150 && cop == 150) return dp[alp][cop];

    for (int i = alp; i <= 150; i++) {
        for (int j = cop; j <= 150; j++) {
            dp[i][j] = (i-alp) + (j-cop);
        }
    }

    sort(problems.begin(), problems.end());

    for (int i = alp; i <= alp_max_req; i++) {
        for (int j = cop; j <= cop_max_req; j++) {
            for (int k = 0; k < n; k++) {
                vector<int> problem = problems[k];
                int alp_req = problem[0];
                int cop_req = problem[1];
                int alp_rwd = problem[2];
                int cop_rwd = problem[3];
                int cost = problem[4];

                // 만약 지금 내가 가진 알고력, 코딩력이 문제를 풀 수 있다면 
                if (alp_req <= i && cop_req <= j) {
                    // 비교해보기 
                    if (alp_rwd == 0 && cop_rwd == 0) continue; 
                    dp[i+alp_rwd][j+cop_rwd] = min(dp[i+alp_rwd][j+cop_rwd], dp[i][j] + cost);
                }
                if (alp_req > i) break;
            }
        }
    }
    return dp[alp_max_req][cop_max_req];
}
int main(){
    string s = "[[0,0,2,1,10], [0, 0, 2, 1, 5]]";
    vector<vector<int>> build_frame;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            int j = i + 1;
            vector<int> vec;
            string number = "";
            while(s[j] != ']') {
                if (s[j] >= '0' && s[j] <= '9') {
                    number += s[j];
                } else if (s[j] == ',') {
                    vec.push_back(atoi(number.c_str()));
                    number = "";
                }
                j++;
            }
            vec.push_back(atoi(number.c_str()));
            number = "";
            i = j;
            build_frame.push_back(vec);
        }
    }
    
    cout << solution(0, 0, build_frame);
    return 0;
}
