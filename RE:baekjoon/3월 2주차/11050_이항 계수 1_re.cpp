#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int dif = (k < n - k) ? n - k : k;

    int ans = 1;
    for (int i = dif + 1; i <= n; i++) {
        ans *= i;
    }

    for (int i = 2; i <= n - dif; i++) {
        ans /= i;
    }

    cout << ans;
    return 0;
}