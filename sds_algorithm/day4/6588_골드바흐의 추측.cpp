#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000005

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool primes[MAX];
    vector<int> oddprimes;
    fill_n(primes, MAX, true);
    primes[1] = false;

    for (int i = 2; i <= MAX; i++) {
        if (primes[i]) {
            for (int j = 2; j * i <= MAX; j++) {
                if (!primes[i*j]) continue;
                primes[i*j] = false;
            }
        }
    }

    for (int i = 3; i <= MAX; i += 2) {
        if (primes[i]) oddprimes.push_back(i);
    }

    int n;
    while(cin >> n) {
        bool isFind = false;
        if (n == 0) break;
        int idx = 0;
        while (idx < oddprimes.size()) {
            int value = n - oddprimes[idx];
            auto it = lower_bound(oddprimes.begin(), oddprimes.end(), value);
            
            if (*it != value || it == oddprimes.end()) idx++;
            else { // 소수 + 홀수 
                cout << n << " = " << oddprimes[idx] << " + "  << *it << '\n';
                isFind = true;
                break;
            } 
        }

        if (!isFind) cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}