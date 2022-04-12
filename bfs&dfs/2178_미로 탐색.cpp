#include <iostream>
#include <string>
#include <queue>

using namespace std;

int matrix[101][101];
int cnt[101][101];

queue<pair<int, int>> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;

bool OOB (int x, int y) {
    return x < 0 || y < 0 || y >= n || y >= m;
}

void bfs(int r, int c) {
    q.push(make_pair(r, c));
    matrix[r][c] = 0;
    cnt[r][c] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!OOB(nx, ny) && matrix[nx][ny] == 1) {
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push(make_pair(nx, ny));
                matrix[nx][ny] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            string ss = s.substr(j, 1);
            matrix[i][j] = stoi(ss);
        }
    }
    bfs(0, 0);
    cout << matrix[n-1][m-1];
    return 0;
}