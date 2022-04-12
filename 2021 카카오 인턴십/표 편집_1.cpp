#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    set<int> v;
    stack<int> st;

    for (int i = 0; i < n; i++) v.insert(i);

    auto it = v.begin();

    while(k--) it++;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') {
            // int num = cmd[i][2] - '0'; // 이렇게 하면 두자리 숫자는 입력 못 받음 
            int num = stoi(cmd[i].substr(2, cmd[i].size()));

            while(num--) it--;
        } else if (cmd[i][0] == 'D') {
            int num = stoi(cmd[i].substr(2, cmd[i].size()));

            while(num--) it++;
        } else if (cmd[i][0] == 'Z') {
            int numz = st.top();
            v.insert(numz);

            st.pop();
        } else { // 'C'
            st.push(*it);
            it = v.erase(it);

            if (it == v.end()) it--;
        }
    }

    string answer(n, 'X');

    for (int i : v) {
        answer[i] = 'O';
    }

    return answer;
}