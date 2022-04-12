#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int w, h;
int map[51][51];
bool isvisit[51][51] = {false}; // 초기화 
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};

void init() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            isvisit[i][j] = false;
            map[i][j] = -1;
        }
    }
}

bool OOB(int x, int y){
    return x < 0 || y < 0 || x >= h || y >= w; 
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    isvisit[x][y] = true;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!OOB(nx, ny) && !isvisit[nx][ny] && map[nx][ny] == 1) {
                q.push(make_pair(nx, ny));
                isvisit[nx][ny] = true;
            }
        }
    }
}

int getCount(int (*map)[51]){
    int cnt = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!isvisit[i][j] && map[i][j] == 1) {
                // bfs 돌기 
                bfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {  
    
    while(1) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        // 섬의 개수 
        cout << getCount(map) << endl;
        init();
    }
}