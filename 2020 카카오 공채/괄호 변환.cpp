#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 어려움 ㅠㅠ 

bool check(string p) {
    int cnt = 0;
    for (auto c : p) {
        if (c == '(') cnt++;
        else cnt--;

        if (cnt < 0) return false;
    }
    return cnt == 0 ? true : false;
}

string solution(string 화p) {
    if (p == "") return p;
    int cnt = 0;
    string u, v;

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') cnt++;
        else cnt--;

        if (cnt == 0) {
            u = p.substr(0, i+1);
            v = p.substr(i+1); // substr() 두번째 인자 생략하면 i부터 마지막까지 
            break;
        }
    }

    if (check(u)) return u + solution(v);

    string ret = "(" + solution(v) + ")";
    for (int i = 1; i < u.size() - 1; i++) {
        ret += (u[i] == '(' ? ")" : "(");
    }

    return ret;
}

int main() {
    cout << solution(")(");
    return 0;
}