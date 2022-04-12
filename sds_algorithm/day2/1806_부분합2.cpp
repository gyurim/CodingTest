#include <iostream>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    
    int arr[100001];
    int start = 0;
    int end = 0;

    long long sum = 0;
    long long minLength = 100001;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];

        if (sum > s) {
            while(1) {
                if (sum - arr[start] >= s && start < i) {
                    sum -= arr[start];
                    start++;
                    
                    minLength = (minLength > i - start + 1) ? i - start + 1 : minLength;
                } else break;
            }
        }
        else if (sum >= s) minLength = i - start + 1;
    }
    
    minLength = (minLength == 100001) ? 0 : minLength;
    cout << minLength;
    return 0;
}