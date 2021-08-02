#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> m;
    map<int, int>::iterator it;

    string num;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num += s[i];    
        } else if (num != "" && (s[i] == ',' || s[i] == '}')) {
            int number = atoi(num.c_str());
            
            if ((it = m.find(number)) != m.end()) {
                // 이미 존재 
                it->second++;
            } else {
                m.insert(make_pair(number, 1));
            }
            num = "";
        } else continue;
    }
    
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    
    for (auto it : vec) {
        answer.push_back(it.first);
        cout << it.first << endl;
    }

    return answer;
}