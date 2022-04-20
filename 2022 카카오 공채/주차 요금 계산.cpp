// 2022.04.20

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cstring>

using namespace std;

int formula(int t, vector<int>& fees) {
    if (t <= fees[0]) return fees[1];
    t -= fees[0];
    // 총 주차 시간을 단위 시간으로 나눈 뒤 올림한 결과 계산 
    // => t + fees[2] - 1 / fees[2] 으로 한 번에 계산 가능 
    int q = (t + fees[2] - 1) / fees[2];
    return fees[1] + q * fees[3];
}

int funcStoi(string s) {
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int stored[10000]; // 직전 입차 시각 
    int cnt[10000] = {0}; // 총 주차 시간 
    memset(cnt, 0, sizeof(cnt));
    memset(stored, -1, sizeof(stored));

    for (auto record : records) {
        stringstream ss(record);
        string time, num, state;
        ss >> time >> num >> state;
        int car_num = atoi(num.c_str());

        if (state == "IN") {
            stored[car_num] = funcStoi(time);
        } else if (state == "OUT") {
            int out_time = funcStoi(time);
            cnt[car_num] += (out_time - stored[car_num]);
            stored[car_num] = -1;
        }
    }

    for (int i = 0; i < 10000; i++) {
        if (stored[i] != -1) 
            cnt[i] += (funcStoi("23:59") - stored[i]);
    }
    
    for (auto c : cnt) {
        if (c == 0) continue;
        answer.push_back(formula(c, fees));
    }

    return answer;
}

int main(){
    vector<int> fees {180, 5000, 10, 600};
    vector<string> records {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    solution(fees, records);
}