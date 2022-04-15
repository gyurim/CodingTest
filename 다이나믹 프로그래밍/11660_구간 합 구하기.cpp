// 2022.04.15

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int matrix[1030][1030];
    long long sum[1030][1030]; 
    memset(sum, 0, sizeof(sum));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
            sum[i][j] = sum[i][j-1] + matrix[i][j];
        }
    }

    int x1, x2, y1, y2;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int answer = 0;

        for (int j = x1; j <= x2; j++) {
            answer += (sum[j][y2] - sum[j][y1 - 1]);
        }
        cout << answer << "\n";
    }
    return 0;
}