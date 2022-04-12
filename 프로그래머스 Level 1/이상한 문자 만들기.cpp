#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;

    for (auto c : s) {
        if (c == ' ') {
            idx = 0;
            answer += ' ';
            continue;
        }

        if (idx % 2 == 0) {
            // 대 
            if (c >= 'a' && c <= 'z') 
                c = c - 'a' + 'A';
            answer += c;
        } else {
            if (c >= 'A' && c <= 'Z') 
                c = c - 'A' + 'a';
            answer += c;
        }
        idx++;
    }
    return answer;
}

int main() {
    cout << solution(" aaaa");
    return 0;
}