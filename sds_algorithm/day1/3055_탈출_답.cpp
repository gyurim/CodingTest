#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define MAX 50

typedef struct
{
        int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int R, C;
string graph[MAX];
pair<int, int> start, dest;
queue<pair<int, int>> river;
int cache[MAX][MAX];

bool oob(int x, int y) {
    return x < 0 || y < 0 || x > C || y > R;
}

int BFS() {
    queue<pair<int, int>> mole;
    mole.push(start);
    cache[start.first][start.second] = 1;

    while(!mole.empty()) {
        int curRiverSize = river.size();
        for (int j = 0; j < curRiverSize; j++) {
            int curY = river.front().first;
            int curX = river.front().second;

            river.pop();

            for (int k = 0; k < 4; k++) {
                int nextY = curY + moveDir[k].y;
                int nextX = curX + moveDir[k].x;

                if (!oob(nextX, nextY)) {
                    if (graph[nextX][nextY] == '.') {
                        graph[nextX][nextY] = '*';
                        river.push({nextY, nextX});
                    }
                }
            }
        }

        int curSize = mole.size();
        for (int i = 0; i < curSize; i++) {
            int y = mole.front().first;
            int x = mole.front().second;

            mole.pop();

            //목적지 도달 시 
            if (y == dest.first && x == dest.second) 
                return cache[y][x]-1;

            // 두더지가 움직일 차례
            for (int j = 0; j < 4; j++) {
                int nextY = y + moveDir[j].y;
                int nextX = x + moveDir[j].x;

                if (!oob(nextX, nextY)) {
                    if (graph[nextY][nextX] != '*' && graph[nextY][nextX] != 'X' && cache[nextY][nextX] == 0) {
                        cache[nextY][nextX] = cache[y][x] + 1;
                        mole.push({nextY, nextX});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int result;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> graph[i];
        for (int j = 0; j < C; j++) {
            if (graph[i][j] == 'S') 
                start = make_pair(i, j);
            else if (graph[i][j] == '*')
                river.push({i, j});
            else if (graph[i][j] == 'D') 
                dest = {i, j};
        }
    }

    result = BFS();

    if (result == -1) cout << "KAKTUS\n";
    else cout << result;

    return 0;
}