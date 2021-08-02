#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

// map을 value 기준으로 내림차순
bool cmp (const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;

    // 오름차순으로 하고 싶으면, > 기호들을 < 로 바꾸면 됨. 
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    map<string, int> set_candidate;

    for (int i = 0; i < orders.size(); i++) {
        vector<char> order;
        string s = orders[i];

        for (int j = 0; j < s.length(); j++ ) {
            order.push_back(s[j]);
        }
        sort(order.begin(), order.end());

        for (int k = 2; k <= order.size(); k++) {
            // 조합할 개수 
            vector<int> flag;
            
            for (int j = 0; j < order.size(); j++) {
                if (j < k) {
                    flag.push_back(0);
                } else {
                    flag.push_back(1);
                }
            }
            // 조합 구하기 
            do {
                string set;
                for (int j = 0; j < flag.size(); j++) {
                    if (flag[j] == 0) {
                        set += order[j];
                    }
                }
                map<string, int>::iterator it;
                if ((it = set_candidate.find(set)) != set_candidate.end()) {
                    // set_candidate 내에 set이 있는 경우 
                    it->second++;
                } else {
                    set_candidate.insert(make_pair(set, 1));
                } 
            } while (next_permutation(flag.begin(), flag.end()));
        }
    }

    // map의 value를 기준으로 내림차순 정렬하기 위해, vector로 값 저장 
    vector<pair<string, int>> vec(set_candidate.begin(), set_candidate.end());
    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < course.size(); i++) {
        int max = 0;
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            string foods = it -> first;
            if (it->second > 1 && foods.length() == course[i]) {
                if (max <= it -> second) {
                    max = it -> second;
                    answer.push_back(foods);
                } 
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}