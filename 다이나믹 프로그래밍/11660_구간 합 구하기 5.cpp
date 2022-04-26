#include <iostream>
using namespace std;

#define MAX 1025
// 누적합 -> 시간 초과 해결 
// 프로그래머스: 파괴되지 않은 건물 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    int sum[MAX][MAX];  
    int num;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            sum[i+1][j+1] = num + sum[i][j+1] + sum[i+1][j] - sum[i][j];
        }
    }
    int x1, x2, y1, y2;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1-1][y1-1];
        cout << ans << "\n";
    }
    return 0;
}