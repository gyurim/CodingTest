#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t; 

    int m, n, x, y;
    while(t--) {
        cin >> m >> n >> x >> y;
        bool isFind = false;

        // 문제 조건: <m:n>이 카잉 달력의 마지막. 따라서, 최소공배수로 최대해를 지정해줘야함 
        int l = lcm(m, n);
        
        for (int i = x; i <= l; i += m) {
            if (i % n == y || (y == n && i % n == 0)) {
                cout << i << endl;
                isFind = true;
                break;
            }
        }
        if (!isFind) cout << "-1" << endl;
    }
    return 0;
}