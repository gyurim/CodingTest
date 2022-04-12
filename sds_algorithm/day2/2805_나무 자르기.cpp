#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long nums[2000001];
int n, m;

long long calculate(long long key) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > key)
            sum += (nums[i] - key);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    // binary search 
    sort(nums, nums + n);
    
    long long low = 0;
    long long high = nums[n-1];
    long long key = 0;
    int result = 0;

    while (low <= high) {
        key = (low + high) / 2;

        long long sum = calculate(key);
        
        if (sum >= m) {
            low = key + 1;
            result = key;

        } else {
            high = key - 1;
        }
    }
    cout << result;

    return 0;
}