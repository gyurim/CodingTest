#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int coin[11];

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    int answer = 0;
    while (k > 0) {
        int idx = upper_bound(coin, coin + n, k) - coin; // 자신보다 같거나 큰 수가 나오는 값의 idx 반환
        
        answer += (k / coin[idx]);
        k = k % coin[idx];
    }

    cout << answer;
    return 0;

}