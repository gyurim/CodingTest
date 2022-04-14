// 2022.04.14

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<string> heads;
    vector<int> numbers;

    int grades[1005] = {0};

    for (auto file : files) {
        string head = "";
        for (int i = 0; i < file.length(); i++) {
            if (file[i] < '0' || file[i] > '9') {
                head += file[i];
            } else {
                file = file.substr(i);
                break;
            }
        }
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        heads.push_back(head);
        
        string number = "";
        for (int i = 0; i < file.length(); i++) {
            if (file[i] >= '0' && file[i] <= '9') 
                number += file[i];
            else {
                file = file.substr(i);
               
                break;
            }
        }
      
        while(true) {
            if (number[0] == '0')
                number = number.substr(1);
            else break;
        }

        numbers.push_back(atoi(number.c_str()));
    }

    vector<string> sorted_heads = heads;
    sort(sorted_heads.begin(), sorted_heads.end());

    for (int i = 0; i < heads.size(); i++) {
        int idx = find(sorted_heads.begin(), sorted_heads.end(), heads[i]) - sorted_heads.begin() + 1;
        grades[i] = idx * 1001;
    }

    vector<int> sorted_numbers = numbers;
    sort(sorted_numbers.begin(), sorted_numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        int idx = find(sorted_numbers.begin(), sorted_numbers.end(), numbers[i]) - sorted_numbers.begin() + 1;
        grades[i] += idx;
        grades[i] *= 1001;
    }

    vector<pair<int, int>> info;

    for (int i = 0; i < files.size(); i++) {
        info.push_back({grades[i], i});
    }

    sort(info.begin(), info.end());

    for (int i = 0; i < info.size(); i++) {
        int idx = info[i].second;
        answer.push_back(files[idx]);
        // cout << files[idx] << endl;
    }
    return answer;
}

int main() {
    vector<string> files {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
    solution(files);
}