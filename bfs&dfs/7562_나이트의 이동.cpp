#include <iostream>
#include <queue>
#include <cstdlib>
#include <string.h> // memset

using namespace std;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int l;
int curX, curY, moveX, moveY;
int minCnt = 0;

bool isVisited[301][301] = {false};

bool oob (int x, int y){
    return x < 0 || x >= l || y < 0 || y >= l;
}
void func(int x, int y) {
    int cnt = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, cnt});
    isVisited[x][y] = true;

    // if (x == moveX && y == moveY) {
    //     minCnt = 0;
    //     return;
    // }

    while (!q.empty()) {
        pair<int, int> front = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (front.first == moveX && front.second == moveY) {
            // minCnt = (minCnt == 0) ? q.front().second : min(q.front().second, minCnt);
            minCnt = cnt;
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];

            if (!oob(nx, ny) && !isVisited[nx][ny]) {
                q.push({{nx, ny}, cnt+1});
                isVisited[nx][ny] = true;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!oob(nx, ny) && !isVisited[nx][ny]) {
            isVisited[nx][ny] = true;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> l;
        cin >> curX >> curY;
        cin >> moveX >> moveY;

        // 최소 몇 번 만에 이동할 수 있는지 출력 
        isVisited[curX][curY] = true;
        func(curX, curY);
        cout << minCnt << endl;

        memset(isVisited, false, sizeof(isVisited));
    }
    return 0;
}