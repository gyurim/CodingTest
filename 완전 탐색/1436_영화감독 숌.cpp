#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long num = 666;
    int cnt = 0;
    
    while (cnt != n) {
        string s = to_string(num);
        if (s.find("666") != string::npos) {
            cnt++;
        }
        num++;
    }
    if (num == 666) cout << num;
    else cout << num-1;
    return 0;
}