#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i = 0; i < 10;) {
        int idx = s.find(nums[i]);
        if (idx != string::npos) {
            s = s.substr(0, idx) + to_string(i) + s.substr(idx + nums[i].length());
        } else i++;
    }
    
    answer = atoi(s.c_str());

    return answer;
}

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

char convert(string num) {
    if (num == "zero") return '0';
    if (num == "one") return '1';
    if (num == "two") return '2';
    if (num == "three") return '3';
    if (num == "four") return '4';
    if (num == "five") return '5';
    if (num == "six") return '6';
    if (num == "seven") return '7';
    if (num == "eight") return '8';
    if (num == "nine") return '9';
    return ' ';
}

int solution(string s) {
    int answer = 0;
    string s_answer = "";
    string num = "";
    for (auto c : s) { 
        if (c >= '0' && c <= '9') {
            s_answer += c;
            
        }
        else {
            num += c;
            char cv = convert(num);
            if (cv != ' ') {
                s_answer += cv;
                num = "";
            }
        }
    }
    s_answer += num;
    answer = atoi(s_answer.c_str());
    return answer;
}

int main() {
    cout << solution("23four5six7");
    return 0;
}
*/