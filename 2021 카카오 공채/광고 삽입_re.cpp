// 2022.04.30
//등장 가능한 시각의 수: 360,000개 -> 이를 통해 투 포인터보단 Prefix Sum이 더 맞는 풀이임을 눈치 채야함 

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstring>

#define INF 400000

using namespace std;

int stringToInt(string time) {
    return atoi(time.substr(0, 2).c_str()) * 3600 + atoi(time.substr(3, 2).c_str()) * 60 + atoi(time.substr(6, 2).c_str());;
}

string intToString(int time) {
    string h = "", m = "", s = "";
    int flag = 3600;
    
    while (flag > 1) { // flag > 0 아니고 > 1
        if (flag == 3600) {
            h = to_string(time/flag);
        } else if (flag == 60) {
            m = to_string(time/flag);
        } 
        time %= flag;
        flag /= 60;
    }
    
    s = to_string(time);
 
    if (h == "0" || h == "1" || h == "2" || h == "3" || h == "4" || h == "5" || h == "6" || h == "7" || h == "8" || h == "9") 
        h = "0" + h;
    if (m == "0" || m == "1" || m == "2" || m == "3" || m == "4" || m == "5" || m == "6" || m == "7" || m == "8" || m == "9") 
        m = "0" + m;
    if (s == "0" || s == "1" || s == "2" || s == "3" || s == "4" || s == "5" || s == "6" || s == "7" || s == "8" || s == "9") 
        s = "0" + s;

    return h + ":" + m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int adv = stringToInt(adv_time);
    int people[INF] = {0};
    
    memset(people, 0, sizeof(people));

    for (auto log : logs) {
        int idx = log.find("-");
        string st = log.substr(0, idx);
        string en = log.substr(idx+1);

        people[stringToInt(st)] += 1;
        people[stringToInt(en)] -= 1; // en은 종료된 시간임을 의미하므로, en+1 해줄 필요가 없었음
    }
    // A. 특정 초에 시청 중인 사람의 수 계산 
    for (int i = 1; i < INF; i++) {
        people[i] += people[i-1];
    }
    // B. 누적 재생시간이 가장 많은 곳 계산 (가장 maxCnt 되는 곳에 대해서 정답처리하게 해줬는데 틀렸었음)
    long long sum[INF] = {0}; // int 아니고 long long 
    memset(sum, 0, sizeof(sum));
    sum[0] = people[0];
    
    for (int i = 1; i < INF; i++) 
        sum[i] = sum[i-1] + people[i];
      
    long long maxCnt = sum[adv - 1];
    int startTime = 0;

    for (int i = 1; i + adv < INF; i++) {
        long long dif = sum[i + adv - 1] - sum[i - 1]; 
        if (dif > maxCnt) {
            startTime = i;
            maxCnt = sum[i + adv - 1] - sum[i - 1];
        }
    }
    string answer = intToString(startTime);
    return answer;
}

int main() {
    // string play_time = "02:03:55";
    // string adv_time = "00:14:15";
    // vector<string> logs = {"01:20:15-01:45:14", "00:25:50-00:48:29", "00:40:31-01:00:00", "01:37:44-02:02:30", "01:30:59-01:53:29"};

    // string play_time = "99:59:59";
    // string adv_time = "25:00:00";
    // vector<string> logs = {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"};
    
    string play_time = "50:00:00";
    string adv_time = "50:00:00";
    vector<string> logs = {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"};
    cout << solution(play_time, adv_time, logs);
    return 0;
}