#include <iostream>
#include <algorithm>

using namespace std;

int w[100005];

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w, w+n);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        ans = max(ans, w[n-i]*i);
        
    cout << ans;
    return 0;
    
}