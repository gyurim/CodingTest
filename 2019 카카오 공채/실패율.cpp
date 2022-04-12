#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
    if (a.first != b.first) return a.first > b.first; // 내림차순 
    else return a.second < b.second; // 오름차순 
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> reach(N+2);
    vector<int> noreach(N+2);
    vector<pair<double, int>> vec;

    for (auto stage : stages) {
        for (int i = 1; i <= stage; i++)
            reach[i]++;

        noreach[stage]++;
    }

    for (int i = 1; i <= N; i++) {
        double ans = 0;
        if (reach[i] == 0) ans = 0;
        else ans = (double) noreach[i] / reach[i];

        vec.push_back({ans, i});
    }

    sort(vec.begin(), vec.end(), cmp);
    
    for (auto v : vec)
        answer.push_back(v.second);

    return answer;
}