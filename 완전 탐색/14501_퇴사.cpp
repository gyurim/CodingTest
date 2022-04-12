#include <iostream>
#include <algorithm>
using namespace std;

int period[17] = {0};
int payments[17] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> period[i] >> payments[i];
    }

    for (int i = n; i > 0; i--) {
        if (i + period[i] > n + 1) {
            // 0을 대입해주면 안된다. 
            // 의미없다고 0으로 초기화시키면 안되고 지금까지의 최대 이익을 복사해줘야함. 
            payments[i] = payments[i+1]; 
        } else {
            payments[i] = max(payments[i+1], payments[i] + payments[i + period[i]]);
        }
    }
    cout << payments[1] << endl;
    return 0;
}