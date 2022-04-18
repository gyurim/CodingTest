// 2022.04.18

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;

    char word = 'A' - 1;
    int cnt;
    string tmp = "";
    for (cnt = 1; cnt <= 26; cnt++) {
        word++;
        tmp = word;
        dict.insert({tmp, cnt});
    }
    
    int idx = 0;
    string w = "";
    string c = "";

    while(true) {
        // 가장 긴 w 찾기 
        map<string, int>::iterator it;
        map<string, int>::iterator prev;
        bool isEnd = false;
        for (int i = idx; i < msg.length(); i++) {
            w += msg[i];
            it = dict.find(w);
            if (it == dict.end()) {
                idx = i;
                answer.push_back(prev->second);
                break;
            } else {
                prev = it;
                if (i == msg.length()-1) {
                    answer.push_back(prev->second);
                    isEnd = true;
                }
            }
        }
        
        if(isEnd) break;

        // 사전 추가 
        it = dict.find(w);
        if (it == dict.end()) {
            dict.insert({w, cnt++});
        }
        
        w = "";
    }
    return answer;
}

int main() {
    solution("KAKAO");
    return 0;
}