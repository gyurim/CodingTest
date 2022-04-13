// 2022.04.12 

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> um;
    vector<pair<string, string>> vec;

    for (auto r : record) {
        vector<string> info;
        while (true) {
            int idx = r.find(" ");
            string token = "";
            if (idx == string::npos) {
                token = r;
                info.push_back(token);
                break;
            }
            else {
                token = r.substr(0, idx);
                info.push_back(token);
            }
            r = r.substr(idx + 2);
        }

        if (info[0] == "Enter") {
            um[info[1]] = info[2];
            vec.push_back({info[0], info[1]});
        } else if (info[0] == "Leave") {
            vec.push_back({info[0], info[1]});
        } else if (info[0] == "Change") {
            um[info[1]] = info[2];
        }
    }

    for (auto v : vec) {
        string nickname = um[v.second];
        if (v.first == "Enter") {
            string cmd = nickname + "님이 들어왔습니다.";
            cout << cmd << endl;
            answer.push_back(cmd);
        } else if (v.first == "Leave") {
            string cmd = nickname + "님이 나갔습니다.";
            cout << cmd << endl;
            answer.push_back(cmd);
        }
    }
    return answer;
}

int main() {
    vector<string> vec {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    solution(vec);
}