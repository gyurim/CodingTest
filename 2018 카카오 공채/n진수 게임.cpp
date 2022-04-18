// 2022.04.18

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// int to char 
/*
int n = 9;
char c = n + '0';
*/
char arrhex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
// change 부분 틀렸었음. 0 ~ 9 까지도 char형으로 배열에 저장하고 값만 불러오는 형태로 바꾸었더니 해결됨 
stack<char> change(int n, int num) {
    stack<char> st;

    int m = num / n;
    int r = num % n;

    st.push(arrhex[r]);

    if (m == 0) 
        return st;

    while (m > 0) {
        st.push(arrhex[m % n]);
        m /= n;
    }
    return st;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int t_cnt = 0;
    int m_cnt = 1;

    int number = -1; // 10진수 
    int idx = 0;

    stack<char> st;
    char cur;

    while(t_cnt < t) {
        if (st.empty()) {
            st = change(n, ++number);
        } 
        
        if (!st.empty()) {
            cur = st.top();
            st.pop();
        } 
        cout << cur;
        if (m_cnt == p) { // 튜브의 차례
            answer.push_back(cur);
            t_cnt++; 
        }

        if (m_cnt == m) m_cnt = 0;
        m_cnt++;
    }
    return answer;
} 

int main() {
    solution(11, 5, 10, 1);
}