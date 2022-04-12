#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    // 분배 법칙을 사용해서 풀어야하는 문제 .. 
    string s;
    stack<char> st;
    cin >> s;
    long long result = 0;
    int temp = 1;

    for (int i = 0; i < s.length(); i++)
    {
        int num;
        if (s[i] == '(')
        {
            temp *= 2;
            st.push('(');
        }
        else if (s[i] == '[')
        {
            temp *= 3;
            st.push('[');
        } 
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() != '(') {
                result = 0;
                break;
            }

            if (s[i-1] == '(') {
                result += temp;
            }
            st.pop();
            temp /= 2;
        }
        else if (s[i] == ']')
        {
            if (st.empty() || st.top() != '[') {
                result = 0;
                break;
            }

            if (s[i-1] == '[') {
                result += temp;
            }
            st.pop();
            temp /= 3;
        }
    }
    
    if (!st.empty()) result = 0;

    cout << result;
    return 0;
}