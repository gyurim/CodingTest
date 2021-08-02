#include <string>
#include <vector>
#include <iostream>
#include <cmath>  

using namespace std;

// 덜함 

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> str1s;
    vector<string> str2s;

    cout << "str1" << endl;

    for (int i = 0; i < str1.length() - 1; i++) {
        char c1;
        char c2;

        if (str1[i] >= 'a' && str1[i] <= 'z') {
            c1 = str1[i] - 'a' + 'A';
        } else c1 = str1[i];

        if (str1[i+1] >= 'a' && str1[i+1] <= 'z') {
            c2 = str1[i+1] - 'a' + 'A';
        } else c2 = str1[i+1];

        cout << "c1: " << c1 << " c2: " << c2 << endl; 
        
        // 만약 c1이나 c2가 특수 문자 들어가있으면 push 안함 
        // 대문자 == 소문자 
         
        if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z') {
            string s;
            s += c1;
            s += c2;
            str1s.push_back(s);
        } 
    }

    cout << "str2" << endl; 

    for (int i = 0; i < str2.length() - 1; i++) {
        char c1;
        char c2;

        if (str2[i] >= 'a' && str2[i] <= 'z') {
            c1 = str2[i] - 'a' + 'A';
        } else c1 = str2[i];

        if (str2[i+1] >= 'a' && str2[i+1] <= 'z') {
            c2 = str2[i+1] - 'a' + 'A';
        } else c2 = str2[i+1];

        cout << "c1: " << c1 << " c2: " << c2 << endl; 

        if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z') {
            string s;
            s += c1;
            s += c2;
            str2s.push_back(s);
        } 
    }

    int same = 0;
    int total = 0;
    cout << "str1s.size: " << str1s.size() << " /str2s.size(): " << str2s.size() << endl;

    for (int i = 0; i < str1s.size(); i++) {
        for (int j = 0; j < str2s.size(); j++) {         
            if (str1s[i] == str2s[j]) {
                cout << "str1s: " << str1s[i] << " / str2s: " << str2s[j] << endl; 
                same++;
            }
        }
    }

    if (same == str2s.size() * str1s.size()) {
        total = str2s.size() + str1s.size();
        if (str2s.size() < str1s.size()) same = str2s.size();
        else same = str1s.size();
    } else total = str2s.size() + str1s.size() - same;

    cout << "total: " << total << endl;
    cout << "same: " << same << endl;

    int result;

    if (total == 0) {
        result = 65536;
    } else {
        result = trunc((same * 65536) / total);
    }
    
    

    answer = result;
    return answer;
}