#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool checkString(string s) {
    stack<char> st;
    
    for (auto c : s) {
        if (c == '(') st.push('(');
        else if (c == '{') st.push('{');
        else if (c == '[') st.push('[');
        else if (c == ')') {
            if (st.size() == 0) return false;
            if (st.top() == '(') st.pop();
            else return false;
        } else if (c == '}') {
            if (st.size() == 0) return false;
            if (st.top() == '{') st.pop();
            else return false;
        } else if (c == ']') {
            if (st.size() == 0) return false;
            if (st.top() == '[') st.pop();
            else return false;
        }
    }
    
    if (st.size() > 0) return false; // 이 부분 없어서 틀렸음 ㅜㅜ 
    return true;
}

int solution(string s) {
    int answer = 0;
    int r = s.length();
    
    for (int i = 0; i < r; i++) {
        string cur = s.substr(i);
        cur += s.substr(0, i);
        
        if (checkString(cur))
            answer++;
    }
    return answer;
}