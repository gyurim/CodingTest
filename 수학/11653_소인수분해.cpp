#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> primes;
    // 방법 1
    /*
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    if (n != 1) cout << n;
    */
    // 방법 2
    while (n > 1) {
        if (n % i == 0) {
            n /= i;
            primes.push_back(i);
        } else {
            i++;
            if (i*i > _n) {
                primes.push_back(n);
                break;
            }
        }
    }

    for (int j = 0; j < primes.size(); j++)
        cout << primes[j] << '\n';

    return 0;
}