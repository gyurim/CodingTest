#include <iostream>
using namespace std;

long long d[100001] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        d[i] = d[i-1] + num;
    }
    int i, j;

    while(m--) {
        cin >> i >> j;
        cout << d[j] - d[i-1] << "\n";
    }
    return 0;
}