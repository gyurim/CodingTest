#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int rgb[1002][3];
int d[1002][3];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> rgb[i][j];

            if (i == 0) {
                d[i][j] = rgb[i][j];
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            vector<int> notDuplicated;
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                notDuplicated.push_back(d[i-1][k]);
            }
            d[i][j] = rgb[i][j] + *min_element(notDuplicated.begin(), notDuplicated.end());
        }
    }
    
    int result = min(d[n-1][0], min(d[n-1][1], d[n-1][2]));
    cout << result;

    return 0;
}