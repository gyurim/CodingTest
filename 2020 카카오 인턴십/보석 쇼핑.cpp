#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map<string, int> m;
    set<string> num(gems.begin(), gems.end());

    int min, start = 0, end = 0;
    for (auto s : gems) {
        m[s]++;
        // 보석을 모두 포함하는 지점까지 end 이동 
        if (m.size() == num.size()) break;
        end++;
    }

    min = end - start; // 구간 중 가장 짧은 구간을 구하기 위해서 
    answer[0] = start + 1;
    answer[1] = end + 1;

    while (end < gems.size()) {
        string key = gems[start];
        m[key]--;
        start++;

        if (m[key] == 0) {
            end++;
            for (; end < gems.size(); end++) {
                m[gems[end]]++;
                if (key == gems[end]) break; // 뒤쪽에서 key를 찾음 
            }
            if (end == gems.size()) break;
        }

        if (min > end - start) {
            answer[0] = start + 1;
            answer[1] = end + 1;
            min = end - start;
        }
    }  
    return answer;
}

// 시간 초과 
// 정확성: 33.3, 효율성: 22.2 
/*
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> m;

    for (auto gem : gems) {
        m.insert({gem, 0});
    }

    int left = 0;
    int right = 0;

    auto it = m.find(gems[left]);
    it->second++;
    int cnt = 1;
    int minCnt = 100005;
    int x = 0, y = 0;

    while (left < gems.size()) {
        if (right >= gems.size()) break;

        bool isAssemble = true;
        for (auto ms : m) {
            if (ms.second == 0) {
                isAssemble = false;
                break;
            }
        }

        if (!isAssemble) {
            right++;
            if (right <= gems.size() - 1) {
                it = m.find(gems[right]);
                it->second++;
                cnt++;
            }
        } else {
            if (minCnt > cnt) {
                minCnt = cnt;
                x = left;
                y = right;
            }

            it = m.find(gems[left]);
            if (it->second > 0)
                it->second--;
            left++;
            cnt--;
        }
    }
    answer.push_back(x+1);
    answer.push_back(y+1);
    return answer;
}
*/
int main() {
    vector<string> vec {"DIA", "DIA", "RUBY"};
    solution(vec);
    return 0;
}