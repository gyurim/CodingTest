#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool alphabetCheck(string s) {
    bool isRight = true;
    for (auto c : s) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            continue;
        else {
            isRight = false;
            break;
        }
    }
    return isRight;
}

int solution(vector<string> logs) {
    vector<string> title {"team_name : ", "application_name : ", "error_level : ", "message : "};
    int answer = 0;
    for (int i = 0; i < logs.size(); i++) {
        
        string log = logs[i];
        if (log.length() >= 100) {
            answer++;
            continue;
        }
        
        int idx = log.find(title[0]);
        for (int j = 0; j < title.size(); j++) {
            // title 체크 
            if (idx == string::npos) {
                answer++;
                break;
            }
            log = log.substr(title[j].length(), log.length() - title[j].length());

            // 형식 체크 
            if (j == title.size() - 1) {
                if (!alphabetCheck(log)) {
                    answer++;
                    break;
                }
            } else {
                if ((idx = log.find(title[j+1])) != string::npos) {
                    string contents = log.substr(0, idx - 1); // 공백 생략 
                    if (!alphabetCheck(contents)) {
                        answer++;
                        break;
                    }
                    log = log.substr(idx, log.length() - idx);
                } 
            }
        }
    }
    return answer;
}

int main(){
    // vector<string> vec {
    //     "team_name : db application_name : dbtest error_level : info message : test", "team_name : test application_name : I DONT CARE error_level : error message : x", "team_name : ThisIsJustForTest application_name : TestAndTestAndTestAndTest error_level : test message : IAlwaysTestingAndIWillTestForever", "team_name : oberervability application_name : LogViewer error_level : error"
    // };
    vector<string> vec {
        "team_name : MyTeam application_name : YourApp error_level : info messag : IndexOutOfRange", "no such file or directory", "team_name : recommend application_name : recommend error_level : info message : RecommendSucces11", "team_name : recommend application_name : recommend error_level : info message : Success!", " team_name : db application_name : dbtest error_level : info message : test", "team_name     : db application_name : dbtest error_level : info message : test", "team_name : TeamTest application_name : TestApplication error_level : info message : ThereIsNoError"
    };
    cout << solution(vec);
    return 0;
}