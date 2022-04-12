#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[10001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0, sum = 0, cnt = 0;
    while (true) {
        if (sum >= m) {
            if (sum == m) cnt++;
            sum -= arr[left++];
        } else if (right == n) {
            break;
        } else {
            sum += arr[right++];
        }
    }
    cout << cnt;

    return 0;
}