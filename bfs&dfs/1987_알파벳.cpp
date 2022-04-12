#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int r, c;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char matrix[21][21];
bool isVisited[101];
queue<pair<int, int>> q;
int answer = 0;

bool oob (int x, int y) {
    return x >= r || x < 0 || y >= c || y < 0;
}

void bfs(int x, int y, int cnt) {
    answer = max(answer, cnt);
    
    if (x == r-1 && y == c-1) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!oob(nx, ny)) {
            // cout << nx << ", " << ny << endl;
            if (!isVisited[matrix[nx][ny] - 'A']) {
                isVisited[matrix[nx][ny] - 'A'] = true;
                bfs(nx, ny, cnt+1);
                isVisited[matrix[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            matrix[i][j] = s[j];
        }
    }
    isVisited[matrix[0][0] - 'A'] = true;
    bfs(0, 0, 1);
    cout << answer;
    return 0;
}