// 2022.05.06 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<string> sentences, int n) {
    set<char> alpha;
    vector<char> np;

    for (auto sc : sentences) { 
        for (auto c : sc) {
            if (c >= 'A' && c <= 'Z') {
                alpha.insert(c - 'A' + 'a');
                alpha.insert(' ');
            } else if (c >= 'a' && c <= 'z') 
                alpha.insert(c);
        }
    }

    for (auto a : alpha)
        np.push_back(a);
    
    vector<bool> flag;
    for (int i = 0; i < np.size(); i++) {
        if (i < n) flag.push_back(0);
        else flag.push_back(1);
    }

    int answer = 0; 
    // 순열 
    do {
        int score = 0; 
        vector<char> useAlpha; // 선택한 알파벳 (n개)
        for(int i = 0; i < flag.size(); i++) {
            if (flag[i] == 0) {
                useAlpha.push_back(np[i]);
            }
        }

        for (auto sentence : sentences) {
            bool getScore = true;
            int bigCnt = 0; // 대문자 개수 세놓기 (추가 점수)
            
            for (auto c : sentence) {
                if (c >= 'a' && c <= 'z') {
                    if (find(useAlpha.begin(), useAlpha.end(), c) != useAlpha.end()) continue;
                    else {
                        getScore = false;
                        break;
                    }
                }
                
                if (c >= 'A' && c <= 'Z') {
                    c = c - 'A' + 'a';
                    if ((find(useAlpha.begin(), useAlpha.end(), c) != useAlpha.end()) && (find(useAlpha.begin(), useAlpha.end(), ' ') != useAlpha.end())) {
                        bigCnt++;
                        continue;
                    } else {
                        getScore = false;
                        break;
                    }
                }
            }
            if (getScore) 
                score += (sentence.length() + bigCnt);
        }

        answer = max(answer, score);
        
    } while (next_permutation(flag.begin(), flag.end()));
    return answer;
}

int main() {
    vector<string> sentences {"line in line", "LINE", "in lion"};
    // vector<string> sentences {"ABcD", "bdbc", "a", "Line neWs"};
    cout << solution(sentences, 5);
    return 0;
}