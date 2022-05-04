#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int stringToInt(string s) {
    string h = s.substr(0, 2);
    string m = s.substr(3, 2);
    return atoi(h.c_str()) * 60 + atoi(m.c_str());
}

string intToString(int i) {
    int h = i / 60;
    int m = i % 60;

    string sh = (h < 10) ?  "0" + to_string(h) : to_string(h);
    string sm = (m < 10) ? "0" + to_string(m) : to_string(m);

    return sh + ":" + sm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> sorted;
    queue<int> q;

    for (auto t : timetable) {
        sorted.push_back(stringToInt(t));
    }

    sort(sorted.begin(), sorted.end());

    for (auto s : sorted) {
        q.push(s);
    }

    int busTime = 540; // 9시 
    int cnt = 0; 
    int last_cnt = 0; // 마지막 버스에 타는 승객 수 
    int last = 0; // 마지막 버스의 마지막 승객 

    for (int i = 0; i < n; i++) {
        while (cnt < m) {
            if (busTime >= q.front()) {
                if (i == n-1 && q.size() > 0) {
                    last_cnt++; 
                    last = q.front();
                }
                q.pop();
            }
            cnt++;
        }

        // 마지막 
        if (i < n-1) busTime += t; // 다음 버스 배차 시간 
        cnt = 0;
    }

    if (last_cnt == m) 
        answer = intToString(last - 1);
    else if (last_cnt < m) 
        answer = intToString(busTime);
    
    // cout << "답: " << answer;
    return answer;
}

int main() {
    // vector<string> timetable {"08:00", "08:01", "08:02", "08:03"};
    // solution(1, 1, 5, timetable);
    
    // vector<string> timetable {"09:10", "09:09", "08:00"};
    // solution(2, 10, 2, timetable);
    
    vector<string> timetable {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};
    solution(10, 60, 45, timetable);
    return 0;
}