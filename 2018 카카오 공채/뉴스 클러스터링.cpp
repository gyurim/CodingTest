#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace std;

string changeStr(string str) {
    string changedStr = "";
    for (auto c : str) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
            changedStr += c;
        } else if (c >= 'a' && c <= 'z') {
            changedStr += c;
        } else {
            changedStr = "";
            break;
        }
    }
    return changedStr;
}

int solution(string str1, string str2) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, int> m1;
    map<string, int> m2;
    set<string> sameStr;
    set<string> notSameStr;

    for (int i = 0; i < str1.length()-1; i++) {
        string s = "";
        s += str1[i];
        s += str1[i+1];

        s = changeStr(s);
        if (s == "") continue;

        notSameStr.insert(s);

        auto it = m1.find(s);
        if (it == m1.end()) m1.insert({s, 1});
        else it->second++;
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        string s = "";
        s += str2[i];
        s += str2[i+1];

        s = changeStr(s);
        if (s == "") continue;

        notSameStr.insert(s);

        auto it = m2.find(s);
        if (it == m2.end()) m2.insert({s, 1});
        else it->second++;

        // m1과 비교 
        auto isSame = m1.find(s);
        if (isSame != m1.end()) 
            sameStr.insert(s);
    }

    for (auto s : sameStr) {
        auto idx = notSameStr.find(s);
        if (idx != notSameStr.end()) 
            notSameStr.erase(idx);
    }

    int answer;

    if (m1.empty() && m2.empty()) 
        answer = 65536;
    else {
        int sum = 0;
        int same = 0;
        for (auto idx : notSameStr) {
            auto it = m1.find(idx);
            if (it != m1.end()) {
                sum += it->second;
                continue;
            }
            it = m2.find(idx);
            if (it != m2.end()) {
                sum += it->second;
                continue;
            }    
        }

        for (auto idx : sameStr) {
            auto it1 = m1.find(idx);
            auto it2 = m2.find(idx);
            int max = (it1->second < it2->second) ? it2->second : it1->second;
            int min = (it1->second > it2->second) ? it2->second : it1->second;

            same += min;
            sum += max;
        }
        
        answer = same * 65536 / sum;
    }
    return answer;
}

int main() {
    cout << solution("handshake", "shake hands");
    return 0;
}