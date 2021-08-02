#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        int output = i;
        int tmp = i;
        
        while (tmp) {
            output += tmp % 10;
            tmp /= 10;
        }

        if (output == n) {
            result = i;
            break;
        }
    }
    cout << result;
}