#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string result = "";

    // 모든 경우의 수 고려 -> 브루트포스 
    for (int i = 0; i < s.length() - 2; i++) {
        for (int j = i + 1; j < s.length() - 1; j++) {
            // i번째 j번째
            // 뒤집기
            string val;
            for (int u = i; u >= 0; u--) val += s[u];
            
            for (int u = j; u > i; u--) val += s[u];

            for (int u = s.size() - 1; u > j; u--) val += s[u];
            
            if (result == "") result = val; // 반례: abcd -> abdc (O) 

            if (result > val) result = val;
        }
    }

    cout << result; 

    return 0;
}