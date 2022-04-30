// 2022.04.26 

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// dfs backtracking 풀이인거 알아야됨 

vector<vector<string>> comb;
int n;
int answer = 0;
vector<vector<string>> all;

void backtracking(int k, vector<string> vec) {
    if (k == n) {
        // vec 내부에서 중복은 없는지 
        bool correct = true;
        set<string> s;
        s.insert(vec[0]);

        for (int i = 1; i < n; i++) {
            if (s.find(vec[i]) != s.end()) {
                correct = false;
                break;
            } else s.insert(vec[i]);
        }
        
        if (correct) { // 전체 경우의 수에서 중복은 없는지  
            sort(vec.begin(), vec.end());
            bool isSame = false;
            for (auto a : all) {
                if (a == vec) {
                    isSame = true;
                    break;
                }
            }

            if (!isSame){
                answer++;
                // for (auto v : vec) 
                //     cout << v << " ";
                // cout << endl;
                all.push_back(vec);
            }
        }
        return;
    }

    for (int i = 0; i < comb[k].size(); i++) {
        vec.push_back(comb[k][i]);
        backtracking(k + 1, vec);
        vec.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    n = banned_id.size();

    for (int j = 0; j < n; j++) {
        string ban = banned_id[j];
        vector<string> vec;

        for (auto user : user_id) {
            if (user.length() != ban.length()) continue;
            bool correct = true;
            for (int i = 0; i < user.length(); i++) {
                if (ban[i] == '*') continue;
                if (user[i] != ban[i]) {
                    correct = false;
                    break;
                }
            }
            
            if(correct) vec.push_back(user);
        }
        comb.push_back(vec);
    }
    vector<string> vec;
    backtracking(0, vec);

    return answer;
}

int main() {
    vector<string> user_id {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id {"fr*d*", "*rodo", "******", "******"};
    cout << solution(user_id, banned_id);
    return 0;
}