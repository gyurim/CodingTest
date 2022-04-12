#include <iostream>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    int z = (y * 100/ x);

    int result = -1;

    if (x == y) cout << result;
    else if (z == 99) cout << result;
    else {
        // 이분 탐색 
        int low = 0;
        int high = 1000000000;
        int result = 0;

        while (low <= high) {
            int key = (low + high) / 2;
            // 100 을 먼저 곱하고 나눗셈 진행해야함 
            int tmp = (100 * (y + key) / (x + key));
            
            if (tmp > z) {
                high = key - 1;
            } else {
                result = key + 1;
                low = key + 1;
            }
        }
        cout << result;
    }

    return 0;
}