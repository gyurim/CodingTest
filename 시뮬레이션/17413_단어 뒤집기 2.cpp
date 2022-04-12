#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s, output;
    getline(cin, s);
    stack <char> st;

    // 태그일때 ('<', '>' 사이) -> 스택을 쓸 필요없이 출력
    // 태그아닐때 -> 스택 사용해서 출력 
    s += '\n';

    bool isTag = false;
    
    for (char ch : s) {
        if (ch == '<') {
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            isTag = true;
            cout << '<';
        } else if (ch == '>') {
            isTag = false;
            cout << '>';
        } else if (isTag) cout << ch;
        else if (ch == ' ' || ch == '\n') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << ' ';
        } else st.push(ch);
    }
    return 0;
}