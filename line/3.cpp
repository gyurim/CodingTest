#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool isOffice[101] = {false};

vector<int> solution(int num_teams, vector<string> remote_tasks, vector<string> office_tasks, vector<string> employees) {
    vector<int> answer;
    vector<vector<int>> team(11);
    

    for (int i = 0; i < employees.size(); i++) {
        string info = employees[i];
        string team_number = "";
        
        for (int j = 0; j < info.length(); j++) {
            if (info[j] >= '0' && info[j] <= '9') {
                team_number += info[j];
            }
            if (info[j] == ' ') {
                info = info.substr(j + 1, info.size() - j - 1);
                break;
            }
        }

        int t_num = atoi(team_number.c_str());
        team[t_num].push_back(i+1);
        
        stringstream ss(info);
        ss.str(info);
        string word;

        while(ss >> word) {

            for (auto task : office_tasks) { 
                if (task == word) {
                    isOffice[i+1] = true;
                    break;
                }
            }

            if(isOffice[i+1]) break;
        }
    }

    for (int i = 1; i <= num_teams; i++) {
        vector<int> team_member = team[i];
        bool isAllHome = true;

        for (int j = 0; j < team_member.size(); j++) {
            if (isOffice[team_member[j]]) {
                isAllHome = false;
                break;
            }
        }

        if (isAllHome) {
            sort(team_member.begin(), team_member.end());
            isOffice[team_member[0]] = true;
        }
    }

    for (int i = 1; i <= employees.size(); i++) {
        if (!isOffice[i]) {
            answer.push_back(i);
            // cout << i << " ";
        }
    }
    // cout << endl;
    return answer;
}

int main() {
    int num_teams = 3;
    vector<string> remote_tasks {"development","marketing","hometask"};
    vector<string> office_tasks {"recruitment","education","officetask"};
    vector<string> employees {"1 development hometask","1 recruitment marketing","2 hometask","2 development marketing hometask","3 marketing","3 officetask","3 development"};
    solution(num_teams, remote_tasks, office_tasks, employees);
    return 0;
}