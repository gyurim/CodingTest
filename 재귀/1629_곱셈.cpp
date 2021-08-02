#include <iostream>
using namespace std;
using ll = long long;

// 귀납적으로 점화식 
ll pow(ll a, ll b, ll m) {
    if (b == 1) return a % m; // base condition  
    ll val = pow(a, b/2, m);
    val = val * val % m;
    if (b % 2 == 0) return val;
    return val * a % m;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
    return 0;
}

// 시간 초과 
// #include <iostream>
// using namespace std;

// using ll = long long;

// ll multiply(ll a, ll b, ll c) {
//     int val = 1;
//     while(b--) val = val * a % c;
//     return val;
// }

// int main() {
//     long long a, b, c;
//     cin >> a >> b >> c;
//     cout << multiply(a, b, c);
//     return 0;
// }