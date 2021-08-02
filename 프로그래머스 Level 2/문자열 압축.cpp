#include <string>
#include <vector>
#include <algorithm> // max 함수 

using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.length() / 2; i++) {
        string convert, temp;
        int cnt = 1;

        temp = s.substr(0, i);

        for (int j = i; j < s.length(); j += i){
            if (temp == s.substr(j, i)) cnt++; 
            else {
                if (cnt > 1) {
                    convert += to_string(cnt);
                }
                convert += temp;
                // 초기화 과정 
                temp = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1) convert += to_string(cnt);
        convert += temp;

        answer = min((size_t)answer, convert.size()); 
    }
    return answer;
}