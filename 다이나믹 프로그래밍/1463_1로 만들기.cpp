#include <iostream>
using namespace std;

int arr[1000001] = {0};

void dp(int n) { 
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + 1;
        if (i % 3 == 0) {
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
        if (i % 2 == 0) {
            arr[i] = min(arr[i], arr[i/2] + 1);
        }
    }
}

int main(){
    int n;
    cin >> n;
    dp(n);
    cout << arr[n];
    return 0;
}