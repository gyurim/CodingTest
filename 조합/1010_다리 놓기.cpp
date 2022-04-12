#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m, r;
        int answer = 1;
        cin >> n >> m;

        r = m - n;

        if (r > n) {
            for (int j = m; j > r; j--) answer *= j;
            int divide = 1;
            for (int j = 1; j <= n; j++) divide *= j;
            answer /= divide;
        } else {
            for (int j = m; j > n; j--) answer *= j;
            for (int j = 1; j <= r; j++) answer /= j;
        }
        // nCr = n! / (r! * (n-r)!)
        cout << answer << endl;
    }

    return 0;
}