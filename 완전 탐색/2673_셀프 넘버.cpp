#include <iostream>
using namespace std;

int main() {
    bool arr[100001] = {false};
    for (int i = 1; i <= 10000; i++) {
        int num = i;
        int sum = i;
        while(num > 9) {
            sum += num % 10;
            num /= 10;
        }
        sum += num;
        arr[sum] = true;
    }

    for (int i = 1; i <= 10000; i++) {
        if (!arr[i]) cout << i << "\n";
    }
    return 0;
}