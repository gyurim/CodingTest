#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<int> s;
    int cnt = 0;

    for (int i = 0; i < str.length(); i++) {
        
        if (str[i] == '(') {
            if (str[i+1] == ')') {
                cnt += s.size();
                i += 1;
            }
            else 
                s.push(1);
        } else {
            s.pop();
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}