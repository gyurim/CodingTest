#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int n, m;
    cin >> n;
    // long long a = 1, b = 1; // a와 b를 string으로 해야함
    string a, b;

    long long na, nb;
    while(n--) {
        cin >> na;
        a *= na;
    }

    cin >> m;

    while(m--) {
        cin >> nb;
        b *= nb;
    }

    string ans = to_string(gcd(a, b));
    
    if (ans.size() >= 9) {
        for (int i = ans.length() - 9; i < ans.length(); i++) 
            cout << ans[i];
    } else cout << ans;

    return 0;
}