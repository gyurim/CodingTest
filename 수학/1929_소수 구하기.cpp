#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;

    vector<bool>state(n+1, true);
    state[1] = false;

    for (int i = 2; i <= n; i++) {
        if (!state[i]) continue;
        for (int j = 2; i * j <= n; j++) {
            state[i*j] = false;
        }
    }

    for (int i = m; i <= n; i++) {
        if (state[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}