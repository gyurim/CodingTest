#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cost = 1000 - n;
    int cnt = 0;
    while (cost > 0) {
        if (cost >= 500) {
            cost -= 500;
        } else if (cost >= 100) {
            cost -= 100;
        } else if (cost >= 50) {
            cost -= 50;
        } else if (cost >= 10) {
            cost -= 10;
        } else if (cost >= 5) {
            cost -= 5;
        } else if (cost >= 1) {
            cost -= 1;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}