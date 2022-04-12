#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[9][9];
int cpy_map[9][9];
int spread_map[9][9];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int maxArea = 0;

bool oob(int x, int y) {
    return x < 0 || y < 0 || x >= n || y>= m;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!oob(nx, ny) && spread_map[nx][ny] == 0) {
                spread_map[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void spreadVirus(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            spread_map[i][j] = cpy_map[i][j];
        }
    }

    int safeCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread_map[i][j] == 2) {
                // spread 
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread_map[i][j] == 0) safeCnt++;
        }
    }

    maxArea = (maxArea < safeCnt) ? safeCnt : maxArea;
}

void setWall(int cnt){
    if (cnt == 3) {
        spreadVirus();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cpy_map[i][j] == 0) {
                cpy_map[i][j] = 1;
                setWall(cnt+1);
                cpy_map[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // 3개의 벽을 세우고 안전 영역 구하기 (어려웠음ㅠ)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                // map copy
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cpy_map[i][j] = map[i][j];
                    }
                }
                cpy_map[i][j] = 1;
                setWall(1);
                // 다시 원상복귀 ㅠㅠ 생각하는거 어려움.. 
                cpy_map[i][j] = 0;
            }
        }
    }
    cout << maxArea;

    return 0;
}