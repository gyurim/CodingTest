#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool report_map[1005][1005] = {false};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int l = id_list.size();
    vector<int> answer(l);

    map<string, int> user;

    for (int i = 0; i < id_list.size(); i++) {
        user.insert({id_list[i], i});
    }

    for (int i = 0; i < report.size(); i++) {
        string s = report[i];
        int idx = s.find(" ");
        string reporter = s.substr(0, idx);
        string bad_user = s.substr(idx + 1, s.length()-idx-1);

        report_map[user.find(reporter)->second][user.find(bad_user)->second] = 1;
    }

    for (int i = 0; i < id_list.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < id_list.size(); j++) {
            if (i == j) continue;
            if (report_map[j][i] == 1) cnt++;
        }

        if (cnt >= k) {
            for (int j = 0; j < id_list.size(); j++) {
                if (report_map[j][i] == 1) {
                    answer[j]++;
                }
            }
        }
    }

    for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";

    return answer;
}

int main() {
    vector<string> id_list {"muzi", "frodo", "apeach", "neo"};
    vector<string> report {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    solution(id_list, report, 2);


}