// 2022.05.06 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 수집 X 로그 개수 
vector<string> title {"team_name : ", "application_name : ", "error_level : ", "message : "};

int solution(vector<string> logs) {
    int answer = 0;

    for (auto log : logs) {
        bool isRight = true;

        if (log.length() > 100) {
            answer++;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            if (log.substr(0, title[i].length()) != title[i]) {
                isRight = false;
                break;
            }

            log = log.substr(title[i].length());
            int idx = log.find(' ');

            string s = log.substr(0, idx);
            
            for (auto c : s) {
                if (c >= 'a' && c <= 'z') continue;
                if (c >= 'A' && c <= 'Z') continue;

                isRight = false;
                break;
            }
            log = log.substr(idx+1);
            if(!isRight) break;
        }
        
        if (!isRight)
            answer++;
        
    }
    cout << answer;
    return answer;
}

int main() {
    vector<string> logs {"team_name : MyTeam application_name : YourApp error_level : info messag : IndexOutOfRange", "no such file or directory", "team_name : recommend application_name : recommend error_level : info message : RecommendSucces11", "team_name : recommend application_name : recommend error_level : info message : Success!", " team_name : db application_name : dbtest error_level : info message : test", "team_name     : db application_name : dbtest error_level : info message : test", "team_name : TeamTest application_name : TestApplication error_level : info message : ThereIsNoError"};

    solution(logs);
    return 0;
}