#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int matrix[51][51];
queue <pair<int, int>> q;
int result = 0;

void bfs(int r, int c, int d) {
    

    if (matrix[r][c] == 0) {
        matrix[r][c] = 1;
        result++;
        // d = (d > 0) ? d - 1 : d + 3;
    } 
    

}

int main() {
    int n, m, r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    bfs(r, c, d);

    return 0;
}