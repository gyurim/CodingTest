#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    long long total = 1;
    int dif = (n > m) ? n : m;

    for (int i = dif + 1; i <= n + m; i++) {
        total *= i;
    }

    for (int i = 2; i <= n + m - dif; i++) {
        total /= i;
    }

    if (total < k) cout << "-1";
    else {
        int nm = n + m;
        string s = "";
        while(n--) s += "a";
        while(m--) s += "z";

        long long cnt = 1;

        do {
            if (cnt == k) break;
            cnt++;
        } while(next_permutation(s.begin(), s.end()));
        cout << s;
    }
}