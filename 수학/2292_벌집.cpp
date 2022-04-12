#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    
    int i = 0;
    // 등비수열 구현 
    for (int sum = 2; sum <= num; i++) {
        sum += 6 * i;
    }
    if (num == 1) i = 1;
    cout << i;

    return 0;
}