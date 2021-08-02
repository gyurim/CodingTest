#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canChange = false;

// call by value 
string a(string t) {
    // cout << "[a] t: " <<  t.substr(0, t.size()-1) << endl;
    return t.substr(0, t.size()-1);
}

string b(string t) {
    t = t.substr(1, t.size());
    reverse(t.begin(), t.end());
    // cout << "[b] t: " << t << endl;
    return t;
}

void func(const string& s, string t){
    // cout << "t: " << t << endl;
    
    if (s == t) {
        canChange = true;
        return;
    }
    
    if (t.size() <= s.size()) return;
    
    if (t[0] == 'B') func(s, b(t));
    if (t[t.size()-1] == 'A') func(s, a(t));
}

int main() {
    string s, t;
    cin >> s >> t;
    func(s, t);
    
    cout << canChange;
    return 0;
}
// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// bool canChange = false;

// // call by value 
// string a(string s) {
//     s += 'A';
//     return s;
// }

// string b(string s) {
//     s += 'B';
//     reverse(s.begin(), s.end());
//     return s;
    
// }

// void func(string s, const string& t){
//     cout << "s: " << s << endl;

//     if (s == t) {
//         canChange = true;
//         return;
//     }

//     if (s.length() >= t.length()) {
//         return;
//     }

//     func(a(s), t);
//     func(b(s), t);
// }

// int main() {
//     string s, t;
//     cin >> s >> t;
//     func(s, t);
    
//     cout << canChange;
//     return 0;
// }