#include <iostream>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int tmp = 1;
        int cnt = 1;
        while(true) {
            if (tmp % n == 0) break;
            tmp = ((tmp * 10) + 1) % n;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}