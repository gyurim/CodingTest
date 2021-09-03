#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string str;
    int cnt;

    cin >> str >> cnt;

    list<char> l;

    for (int i = 0; i < str.length(); i++) {
        l.push_back(str[i]);
    }

    list<char>::iterator it = l.end();
    // 방법 1
    for (int i = 0; i < cnt; i++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (it != l.begin()) it--;
        } else if (cmd == 'D') {
            if (it != l.end()) it++; 
        } else if (cmd == 'B') {
            if (it != l.begin()) {
                // 커서의 왼쪽 위치 값을 삭제
                // erase는 커서가 가리키는 값 삭제 후 오른쪽 값을 가리킨다. 
                // erase는 iterator 반환 
                it--;
                it = l.erase(it); 
            }
        } else if (cmd == 'P') {
            char input;
            cin >> input;
            l.insert(it, input);
        }
    }

    // 방법 2
    cin.ignore();
    // for (int i = 0; i < cnt; i++) {
    //     string cmd;
    //     getline(cin, cmd);
        
    //     if (cmd[0] == 'L') {
    //         if (it != l.begin()) it--;
    //     } else if (cmd[0] == 'D') {
    //         if (it != l.end()) it++; 
    //     } else if (cmd[0] == 'B') {
    //         if (it != l.begin()) {
    //             it--;
    //             it = l.erase(it); 
    //         }
    //     } else if (cmd[0] == 'P') {
    //         l.insert(it, cmd[2]);
    //     }
    // }

    for (auto x : l) cout << x;
    return 0;
} 