#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;

    // string은 substr 사용해서 자르기 
    int length = s.length();

    for (int i = 0; i < length; i++) {
        bool isright = true;
        // 올바른지 아닌지 판별 
        for (int j = 0; j < length; j++) {
            if (s[j] == '(' || s[j] == '{' || s[j] == '[') {
                st.push(s[j]);
            } else {
                if (st.size() == 0) isright = false;
                if (s[j] == ')' && st.top() != '(') isright = false;
                else if (s[j] == '}' && st.top() != '{') isright = false;
                else if (s[j] == ']' && st.top() != '[') isright = false;

                if (!isright) break;
                st.pop();
            }
        }
        if (isright && st.size() == 0) answer++;
        s = s.substr(1, length) + s.substr(0, 1);
    }
    return answer;
}