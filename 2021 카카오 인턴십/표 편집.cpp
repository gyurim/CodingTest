#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <list>
#include <set>
#include <tuple>

using namespace std;

/************************************************************
* 링크드리스트를 사용한 방법
*************************************************************/
/*
list<int> l;
list<int>::iterator its[1000005];
list<int>::iterator cursor;
stack<pair<int, int>> erased;

string solution(int n, int k, vector<string> cmd) {
    for (int i = 0; i < n; i++) {
        l.push_back(i);
    }
    l.push_back(n);
    auto it = l.begin();

    for (int i = 0; i < n+1; i++) {
        its[i] = it;
        it++;
    }
    cursor = its[k];

    for (auto s : cmd) {
        if (s[0] == 'U') {
            int num = stoi(s.substr(2, 100));
            while(num--) cursor--;
        } else if (s[0] == 'D') {
            int num = stoi(s.substr(2, 100));
            while(num--) cursor++;
        } else if (s[0] == 'C') {
            erased.push({*cursor, *(next(cursor))});
            cursor = l.erase(cursor);
            if(*cursor == n) cursor--;
        } else {
            int cur, nxt;
            tie(cur, nxt) = erased.top();
            erased.pop();
            its[cur] = l.insert(its[nxt], cur);
        }
    }
    string status(n, 'X');
    for (auto x : l) {
        if (x != n) status[x] = 'O';
    }
    cout << status;
    return status;
}
*/

/************************************************************
* 이진 검색 트리를 사용한 방법
// stringstream 쓰니까 시간오류 났음.. (특정 케이스만) 
계속 string stream으로 변환해주는 과정에서 시간이 오래 걸렸던 거 같다. 
*************************************************************/

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    set<int> s;
    stack<int> st;

    for (int i = 0; i < n; i++) 
        s.insert(i);

    auto it = s.find(k);

    for (int i = 0; i < cmd.size(); i++) {
        string c = cmd[i];
        // stringstream ss(c); 

        char ch;
        // ss >> ch;

        if (c[0] == 'U') {
            int num = stoi(c.substr(2, 100));
            while(num--) it--;
        } else if (c[0] == 'D') {
            int num = stoi(c.substr(2, 100));
            while(num--) it++;
        } else if (c[0] == 'C') {
            st.push(*it); // iterator가 가리키고 있는 값
            it = s.erase(it);
            
            if (it == s.end()) it--;
        } else {
            s.insert(st.top());
            st.pop();
        }
    }

    string status(n, 'X');
    for (auto x : s) {
        status[x] = 'O';
    }

    return status;
}
/************************************************************
* 그냥 구현 
* 내가 푼 건데 정확성 + 효율성 테스트 69점 나옴
*************************************************************/
/*
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<pair<int, bool>> matrix;
    stack<int> st;

    for (int i = 0; i < n; i++) 
        matrix.push_back(make_pair(i, true));
    
    int cur = k;
    int size = n;

    for (int i = 0; i < cmd.size(); i++) {
        
        string s = cmd[i];
        stringstream ss(s);
        char c;
        int num;

        ss >> c;

        if (c == 'U') { 
            ss >> num;
            while (num > 0 && cur > 0) {
                if (matrix[cur].second) {
                    num--;
                    cur--;
                } else {
                    cur--;
                }
            }
        } else if (c == 'D') {
            ss >> num;
            while (num > 0 && cur < n - 1) {
                if (matrix[cur].second) {
                    num--;
                    cur++;
                } else {
                    cur++;
                }
            }
        } else if (c == 'C') {
            matrix[cur].second = false;
            st.push(cur);
            
            // O X X O X
            // O O O O O 
            
            if (cur == n - 1) {
                cur--;
                while(true) {
                    if (matrix[cur].second) break;
                    else cur--;
                }
            } else {
                cur++;
                bool rightDirection = true;
                
                if (!matrix[cur].second) {
                    while (true) {
                        if (cur == n - 1 && rightDirection) { 
                            rightDirection = false;
                            cur--;
                        } else if (cur < n - 1 && rightDirection) {
                            cur++;
                        } else if (cur < n - 1 && !rightDirection){
                            cur--;
                        }
                        if (matrix[cur].second) break;
                    }  
                }
            }
        } else {
            int top = st.top();
            st.pop();
            matrix[top].second = true;
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i].second) answer += 'O';
        else answer += 'X';
    }

    // cout << answer;

    return answer;
}

int main() {
    vector<string> cmd = {"C", "C", "C", "U 1", "C"};
    solution(5, 4, cmd);
}
*/