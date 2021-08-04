#include <iostream> 
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int output = n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        char cur;
        map<char, int> m;
        map<char, int>::iterator it;

        for (int j = 0; j < s.length(); j++) {
            if ((it = m.find(s[j])) == m.end()) {
                m.insert(make_pair(s[j], 1));
                cur = s[j];
            } else if (cur != s[j] && (it = m.find(s[j])) != m.end()){
                // not group 
                output--;
                break;
            }
        }
    }
    
    cout << output;
    return 0;
}