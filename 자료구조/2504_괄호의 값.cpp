#include <iostream>
#include <stack>

using namespace std;

int main(){
    string s;
    cin >> s;

    int result = 0;
    int temp = 1;
    bool impossible = false;
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
            temp *= 2;
        } else if (s[i] == '[') {
            st.push(s[i]);
            temp *= 3;
        } else if (s[i] == ']' && (st.empty() || st.top() != '[')){
            impossible = true;
            break;
        } else if (s[i] == ')' && (st.empty() || st.top() != '(')) {
            impossible = true;
            break;
        } else if (s[i] == ')') {
            if (s[i-1] == '(') result += temp;
            temp /= 2;
            st.pop();
        } else if (s[i] == ']') {
            if (s[i-1] == '[') result += temp;
            temp /= 3;
            st.pop();
        }
    }

    if (impossible || !st.empty()) cout << "0";
    else cout << result;

    return 0;
}

// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
//     string str;
//     cin >> str;

//     stack<char> s;
//     long long result = 0;
//     int temp = 1;
//     bool impossible = false;

//     for (int i = 0; i < str.length(); i++) {
//         if (str[i] == '(') {
//             temp *= 2;
//             s.push('(');
//         } else if (str[i] == '[') {
//             temp *= 3;
//             s.push('[');
//         } else if (str[i] == ')' && (s.empty() || s.top() != '(')) {
//             impossible = true;
//             break;
//         } else if (str[i] == ']' && (s.empty() || s.top() != '[')) {
//             impossible = true;
//             break;
//         } else if (str[i] == ')') {
//             if (str[i-1] == '(') {
//                 result += temp;
//             }
//             s.pop();
//             temp /= 2;
//         } else if (str[i] == ']') {
//             if (str[i-1] == '[')
//                 result += temp;
//             s.pop();
//             temp /= 3;
//         }
//     }

//     if (impossible || !s.empty()) cout << "0";
//     else cout << result;

//     return 0;
// }