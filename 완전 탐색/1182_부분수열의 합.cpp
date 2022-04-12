#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int arr[21] = {};

    for (int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        vector<int> flags;
        
        for (int j = 0; j < n; j++) {
            if (j <= i) flags.push_back(0);
            else flags.push_back(1);
        }

        do {
            int sum = 0;
            for (int cnt = 0; cnt < n; cnt++) {
                if (flags[cnt] == 0) {
                    sum += arr[cnt];
                }
            }

            if (sum == s) {
                result++;
            }

        } while (next_permutation(flags.begin(), flags.end()));
    }
    cout << result << endl;
}