#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string s) {
    int answer = 0;

    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");

    answer = stoi(s);
    return answer;
}

/*
char change(string eng) {
    if (eng == "zero") return '0';
    else if (eng == "one") return '1';
    else if (eng == "two") return '2';
    else if (eng == "three") return '3';
    else if (eng == "four") return '4';
    else if (eng == "five") return '5';
    else if (eng == "six") return '6';
    else if (eng == "seven") return '7';
    else if (eng == "eight") return '8';
    else if (eng == "nine") return '9';
    else return '.';
}

int solution(string s) {
    long long answer = 0;
    string eng = "";
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans += s[i];
        } else {
            eng += s[i];
            char re = change(eng);

            if (re != '.') {
                ans += re;
                eng = "";
            } 
        }
    }

    answer = stoll(ans);
    
    return answer;
}
*/