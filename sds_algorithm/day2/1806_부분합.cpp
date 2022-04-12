#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int arr[100001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int left = 0, right = 0, sum = 0, ans = n + 1;
    while (true) {
        if (sum >= s) { // 부분합이 S 이상 
            ans = min(ans, right-left);
            sum -= arr[left++];
        }
        else if (right == n) break;
        else {
            // 부분합이 S 미만인 경우 right를 더해주고 right의 포인트를 오른쪽으로 옮김 
            sum += arr[right++];
        }
    }
    ans = (ans == n + 1 ? 0 : ans);
    cout << ans;
    return 0;
}