#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<int> st;
    int sum = 0;
    int result = 1;
    if (s.length() <= 1)
        sum = 0;
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(2);
                result *= 2;
            }
            else if (s[i] == '[')
            {
                st.push(3);
                result *= 3;
            }
            else if (s[i] == ')')
            {
                if (st.empty() || st.top() != 2 )
                {
                    sum = 0;
                    break;
                }
                st.pop();
                sum += result;
                result /= 2;
                if (i >= 1 && (s[i - 1] == ')' || s[i - 1] == ']'))
                    sum -= (result * 2);
            }
            else if (s[i] == ']')
            {
                if (st.empty() || st.top() != 3) // empty 먼저 체크 안해주면 segment fault 발생! 
                {
                    sum = 0;
                    break;
                }
                st.pop();
                sum += result;
                result /= 3;
                if (i >= 1 && (s[i - 1] == ')' || s[i - 1] == ']'))
                    sum -= (result * 3);
            }
        }
    }

    if (st.size() > 0)
        sum = 0;
    cout << sum;

    return 0;
}