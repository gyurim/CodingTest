#include <iostream>
#include <queue>
using namespace std;

int n;
int matrix[102][102];
bool visit[102][102];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= n;
}

void bfs(int x, int y, int height) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = true;

    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = front.first + dx[i];
            int nextY = front.second + dy[i];

            if (!OOB(nextX, nextY)) {
                if (matrix[nextX][nextY] > height && !visit[nextX][nextY]) {
                    visit[nextX][nextY] = true;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
}

int main() {   
    cin >> n;

    int max = -1;
    int min = 101;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            max = (max < matrix[i][j]) ? matrix[i][j] : max;
        }
    }

    int max_cnt = 0;

    for (int k = 0; k <= max; k++) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                visit[i][j] = false;
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && matrix[i][j] > k) {
                    bfs(i, j, k);
                    cnt++;
                }
            }
        }
        max_cnt = (max_cnt <= cnt) ? cnt : max_cnt;
    }

    cout << max_cnt;
    return 0;

}