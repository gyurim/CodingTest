#include <iostream>
#include <algorithm>

using namespace std;

int alpha[100]; // A: 65 ~ Z: 90 
string odd, even;

int main() {
    string s;
    cin >> s;
    
    for (char i : s) {
        alpha[i]++;
    }
    
    for (char i = 'A'; i <= 'Z'; i++) {
        if (alpha[i] % 2 == 1) { // 1: true, 0 : false 
            odd += i;
        }
        for (int j = 0; j < alpha[i]/2; j++)
            even += i;
    }
    
    if (odd.size() > 1) {
        cout << "I'm Sorry Hansoo";
    } else {
        cout << even;
        cout << odd;
        reverse(even.begin(), even.end()); // 헤더: algorithm
        cout << even;
    }
    return 0;
}

// // 시간초과 
// bool check(string s) {
//     int length = s.length();
//     for (int i = 0; i < length; i++) {
//         if (s[i] != s[length - 1 - i]) return false;
//     }
//     return true;
// }

// int main() {
//     // 팰린드롬 : 앞 뒤를 뒤집어도 똑같은 문자열 
//     string s;
//     cin >> s;
//     sort(s.begin(), s.end());
//     bool checkP = false;
//     do {
//         checkP = check(s);
//         if (checkP) break;
//     } while(next_permutation(s.begin(), s.end()));
    
//     if (checkP) cout << s;
//     else cout << "I'm Sorry Hansoo";
    
//     return 0;
// }