#include <iostream>
#include <queue>
#include <string.h>

// dp로 풀어야됨 -> dp 공부하고 ㄱㄱ
// 메모리 초과 

using namespace std;

int game[100001][4] = {-1};
int n;

int dx[] = {1, 1, 1};
int dy[] = {0, 1, -1};
int maxSum[100001][4] = {0};
int minSum[100001][4];

bool oob(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= 3;
}

void getScore(int x, int y) {
    maxSum[x][y] = game[x][y];
    minSum[x][y] = game[x][y];

    queue<pair<int, int>> q;

    q.push({x, y});
    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];

            if (!oob(nx, ny)) {
                maxSum[nx][ny] = (maxSum[nx][ny] < maxSum[front.first][front.second] + game[nx][ny]) ? maxSum[front.first][front.second] + game[nx][ny] : maxSum[nx][ny]; 
                minSum[nx][ny] = (minSum[nx][ny] > minSum[front.first][front.second] + game[nx][ny]) ? minSum[front.first][front.second] + game[nx][ny] : minSum[nx][ny]; 

                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> game[i][j];
        }
        memset(minSum[i], 1000001, sizeof(int)*3);
    }

    for (int i = 0; i < 3; i++) {
        getScore(0, i);
    }

    int maxNum = 0;
    int minNum = 1000001;

    for (int i = 0; i < 3; i++) {
        maxNum = (maxNum < maxSum[n-1][i]) ? maxSum[n-1][i] : maxNum;
        minNum = (minNum > minSum[n-1][i]) ? minSum[n-1][i] : minNum;
    }
    
    cout << maxNum << " " << minNum;
    
    return 0;
}