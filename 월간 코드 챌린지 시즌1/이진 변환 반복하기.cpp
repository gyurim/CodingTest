#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int bi_cnt = 0;
    int zero_cnt = 0;
    

    while (s != "1") {
        string temp = "";
        cout << "s: "<< s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1'){
                temp += '1';
            } else 
                zero_cnt++;
        }

        bi_cnt++;
        int num = temp.size();
        s = "";
        cout << endl; 
        while (num > 0) {
            s += to_string(num % 2);
            cout << "이진수 s: " << s << endl;
            num /= 2;
        }
        cout << endl; 
    }

    answer.push_back(bi_cnt);
    answer.push_back(zero_cnt);

    return answer;
}