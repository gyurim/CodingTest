#include <iostream>
using namespace std;

int matrix[1025][1025] = {0};

int main() {
    int n , m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 합 구하기 
        int sum = 0;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                sum += matrix[i][j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}