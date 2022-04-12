#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, string> state;
    map<int, int> pay;

    for (int i = 0; i < records.size(); i++) {
        string record = records[i];
        int idx = record.find(" ");
        string time = record.substr(0, idx);
        record = record.substr(idx + 1, record.length() - idx - 1);
        idx = record.find(" ");
        int car = atoi(record.substr(0, idx).c_str());
        record = record.substr(idx + 1, record.length() - idx - 1);
        string history = record;

        if (history == "IN") {
            state.insert({car, time});
        } else if (history == "OUT") {
            // 가격 계산 
            string in_time = state.find(car)->second;
      
            string in_time_hour = in_time.substr(0, 2);
            string in_time_minute = in_time.substr(3, 2);
            string out_time_hour = time.substr(0, 2);
            string out_time_minute = time.substr(3, 2);

            int accumulate = (atoi(out_time_hour.c_str()) - atoi(in_time_hour.c_str())) * 60 + (atoi(out_time_minute.c_str()) - atoi(in_time_minute.c_str()));
            
            if (pay.find(car) == pay.end()) {
                pay.insert({car, accumulate});
            } else {
                pay.find(car)->second += accumulate;
            }
            state.erase(car);
        }
    }

    for (auto it : state) {
        string in_time = it.second;
        
        string in_time_hour = in_time.substr(0, 2);
        string in_time_minute = in_time.substr(3, 2);
        
        int accumulate = (23 - atoi(in_time_hour.c_str())) * 60 + (59 - atoi(in_time_minute.c_str()));

        if (pay.find(it.first) == pay.end()) {
            pay.insert({it.first, accumulate});
        } else {
            pay.find(it.first)->second += accumulate;
        }
    }

    for (auto it : pay) {
        if (it.second > fees[0]) {
            int pays = 0;
            if ((it.second - fees[0]) % fees[2] == 0) 
                pays = fees[1] + ((it.second - fees[0]) / fees[2]) * fees[3];
            else 
                pays = fees[1] + ((it.second - fees[0]) / fees[2] + 1) * fees[3];
            answer.push_back(pays);
        } else {
            answer.push_back(fees[1]);
        }
    }
    return answer;
}

int main() {
    vector<int> fees {180, 5000, 10, 600};
    vector<string> records {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    solution(fees, records);
    return 0;
}