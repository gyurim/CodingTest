#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<double, pair<int, pair<int, int>>>& a, pair<double, pair<int, pair<int, int>>>& b) {
    if (a.first == b.first) {
        if (a.second.first == b.second.first) {
            if (a.second.second.first == b.second.second.first) {
                return a.second.second.second < b.second.second.second;
            }
            return a.second.second.first > b.second.second.first;
        }
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}


vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;

    int number = head2head.size();
       vector<pair<double, pair<int, pair<int, int>>>> infos;

    for (int i = 0; i < number; i++) {
        int lcount = 0;
        int bigWin = 0;
        int ncount = 0;

        string headlog = head2head[i];
        for (int j = 0; j < number; j++) {
            if (headlog[j] == 'N') {
                ncount++; // WWNN의 승률은 100% WWLN의 승률은 66% 따라서 W의 개수가 같더라도 N의 개수에 따라 승률이 달라진다. 즉, 참여한 경기 횟수에 따라 승률은 달라짐.
            }
            else if (headlog[j] == 'W') {
                lcount++;
                if (weights[i] < weights[j]) 
                    bigWin++;
            }
        }
        double winRate = 0;
        if (number != ncount)
            winRate = lcount * 1000000 / (number - ncount); // 10000 딱 필요한 정도만 해주니까 틀렸고 00 더 붙이니까 맞았음 .. 
            
        infos.push_back(make_pair(winRate, make_pair(bigWin, make_pair(weights[i], i+1))));
    }

    sort(infos.begin(), infos.end(), cmp);
    for (int i = 0; i < number; i++) {
        answer.push_back(infos[i].second.second.second);
    }
    return answer;
}