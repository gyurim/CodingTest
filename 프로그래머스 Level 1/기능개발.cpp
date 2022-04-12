#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> time;

    for (int i = 0; i < progresses.size(); i++) {
        int percent = progresses[i];
        int cnt = 0;

        while(percent < 100) {
            percent += speeds[i];
            cnt++;
        }
        time.push_back(cnt);
    }
    int max = time[0];
    int cnt = 1;
    for (int i = 1; i < time.size(); i++) {
        if (max >= time[i]) {
            cnt++;
        } else {
            answer.push_back(cnt);  
            cnt = 1;
            max = time[i];
        }
    }
    answer.push_back(cnt);  

    return answer;
}