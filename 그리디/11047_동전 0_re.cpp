#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> coins;
    int coin;
    for (int i = 0; i < n; i++) {
        cin >> coin;
        coins.push_back(coin);
    }
    
    int ans = 0;
    while (k > 0) {
        for (int i = n - 1; i >= 0; i--) {
            if (k >= coins[i]) {
                k -= coins[i];
                ans++;
                break;
            } 
        }
    }
    cout << ans;

    return 0;
}