#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c, q;
    cin >> r >> c >> q;
    int picture[1005][1005];

    int k;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> k;

            if (i == 1 && j == 1) picture[i][j] = k;
            else if (i == 1) 
                picture[i][j] = picture[i][j-1] + k;
            else if (j == 1) 
                picture[i][j] = picture[i-1][j] + k;
            else picture[i][j] = picture[i-1][j] + picture[i][j-1] + k - picture[i-1][j-1];
        }
    }

    int r1, c1, r2, c2;
    for (int i = 0; i < q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        // 직사각형의 밝기 평균 출력
        int ans = picture[r2][c2] - picture[r2][c1-1] - picture[r1-1][c2] + picture[r1-1][c1-1];
        ans /= (r2 - r1 + 1) * (c2 - c1 + 1);
        cout << ans << "\n";
    }
    return 0;
}