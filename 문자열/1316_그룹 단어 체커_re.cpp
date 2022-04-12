#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string word;
    set<char> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> word;

        // 그룹 단어 체크 
        s.insert(word[0]);
        bool isgroup = true;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] != word[i-1]) {
                if (s.find(word[i]) == s.end()) {
                    s.insert(word[i]);
                } else {
                    isgroup = false;
                    break;
                }
            }
        }

        if (isgroup) cnt++;
        s.clear();
    }
    cout << cnt;
    return 0;
}