#include <iostream>
#include <queue>
using namespace std;

char map[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int r, c;
bool isVisited[51][51] = {false};

queue<pair<int, int>> startQ;
queue<pair<int, int>> waterQ;

pair<int, int> endIdx;

bool oob(int x, int y) {
    return x < 0 || y < 0 || x >= r || y >= c;
}

// 물과 고슴도치가 한꺼번에 진행되는 bfs 
int bfs() {
    int cnt = 0;
    while(!startQ.empty()) {
        cnt++;
        int waterCnt = waterQ.size();

        // water spread 
        while(waterCnt--) {
            int x = waterQ.front().first;
            int y = waterQ.front().second;;
            waterQ.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!oob(nx, ny)) {
                    if (map[nx][ny] == '.') {
                        waterQ.push({nx, ny});
                        map[nx][ny] = '*';
                    }
                }
            }
        }

        // 고슴도치 move 
        int startCnt = startQ.size();
        while(startCnt--) {
            int x = startQ.front().first;
            int y = startQ.front().second;
            isVisited[x][y] = true;
            startQ.pop();

            if (x == endIdx.first && y == endIdx.second) {
                cout << cnt-1;
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!oob(nx, ny)) {
                    if (!isVisited[nx][ny]) {
                        if (map[nx][ny] == '.' || map[nx][ny] == 'D') {
                            startQ.push({nx, ny});
                            isVisited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    cout << "KAKTUS";
    return 0;
}

int main() {
    cin >> r >> c;

    string s;

    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            map[i][j] = s[j];

            if (map[i][j] == 'S')
                startQ.push({i, j});    
            else if (map[i][j] == '*') 
                waterQ.push({i, j});
            else if (map[i][j] == 'D')
                endIdx = {i, j};
        }
    }
    bfs();
    return 0;
}