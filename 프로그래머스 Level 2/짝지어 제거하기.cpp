#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

// 시간 초과 났음 -> 비교하는 문제 : stack 사용해서 해보기 

// int solution(string s)
// {
//     int answer = 0;
    
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] == s[i+1]) {
//             s.erase(s.begin() + i, s.begin() + i + 2);
//             i = -1;

//             if (s.length() == 0) {
//                 answer = 1;
//                 break;
//             }
//         }

//         if (i == s.length() - 2 && s[i] != s[i+1]) {
//             answer = 0;
//             break;
//         }
//     }

//     return answer;
// }

// 비교 횟수를 줄이기 위해 stack 사용 !! 

int solution(string s) {
    stack <int> st;
    int answer = 0;

    for (int i = 0; i < s.length(); i++) {
        if (st.size() > 0) {
            if (st.top() == s[i]) {
                st.pop();
            } else st.push(s[i]);
        } else st.push(s[i]);
    }

    if (st.size() != 0) answer = 0;
    else answer = 1;

    return answer;
}