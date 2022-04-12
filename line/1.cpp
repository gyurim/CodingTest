#include <string>
#include <vector>
#include <iostream>
#include <regex>

using namespace std;

bool islogright(string log) {
    // // 공백 X, 숫자, 특수문자 X
    bool flag = true;

    for (int i = 0; i < log.length(); i++) {
        if (log[i] == ' ') {
            flag = false;
            break;
        }
        if (log[i] >= '0' && log[i] <= '9') {
            flag = false;
            break;
        }
        if ((log[i] >= 'a' && log[i] <= 'z') || (log[i] >= 'A' && log[i] <= 'Z')) {
            continue;
        } else {
            flag = false;
            break;
        }
    }
    return flag;
}

int solution(vector<string> logs) {
    int answer = 0;

    for (auto log : logs) {
        if (log.length() >= 100) {
            answer++;
            continue;
        } 

        int idx = -1;
        if ((idx = log.find("team_name : ")) != string::npos) {
            if (idx > 0) {
                answer++;
                continue;  
            }
            log = log.substr(idx, log.size()-idx);
        } else {
            answer++;
            continue;
        }
        if ((idx = log.find(" application_name : ")) != string::npos) {
            // team_name 형식 찾기 
            string test_s = log.substr(12, idx-12);
            
            log = log.substr(idx, log.size()-idx);
            
            if (!islogright(test_s)) {
                answer++;
                continue;
            }
        } else {
            // answer_name 제목 X
            answer++;
            continue;
        }

        if ((idx = log.find(" error_level : ")) != string::npos) {
            // answer_name 형식 찾기 
            string test_s = log.substr(20, idx-20);
            log = log.substr(idx, log.size()-idx);
            
            if (!islogright(test_s)) {
                answer++;
                continue;
            }
        } else {
            // error_level 제목 X
            answer++;
            continue;
        }

        if ((idx = log.find(" message : ")) != string::npos) {
            // error_level 형식 찾기 
            string test_s = log.substr(15, idx-15);
            log = log.substr(idx, log.size()-idx);
            if (!islogright(test_s)) {
                answer++;
                continue;
            }
        } else {
            // message 제목 X 
            answer++;
            continue; 
        }
        
        log = log.substr(11, log.size() - 11);
        // message 형식 찾기 
        if (!islogright(log)) {
            answer++;
            continue;
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