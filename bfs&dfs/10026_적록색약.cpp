#include <iostream>
#include <queue>

using namespace std;

bool visit[101][101];
queue <pair<int, int>> q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char area[101][101];

int n;
int cnt = 0;
 
void bfs(char alphabet){
    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = front.first + dx[i];
            int y = front.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < n) {
                if (area[x][y] == alphabet && !visit[x][y]) {
                    q.push(make_pair(x, y));
                    visit[x][y] = true;
                }
            }
        }
    }
    cnt++;
}

void watchArea(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (area[i][j] == 'R' && !visit[i][j]) {
                q.push(make_pair(i, j));
                visit[i][j] = true;
                bfs('R');
            }
            
            if (area[i][j] == 'B' && !visit[i][j]) {
                q.push(make_pair(i, j));
                visit[i][j] = true;
                bfs('B');
            }

            if (area[i][j] == 'G' && !visit[i][j]) {
                q.push(make_pair(i, j));
                visit[i][j] = true;
                bfs('G');
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++ ) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
        }
    }

    // 적록 색약이 아닌 사람 
    watchArea();
    cout << cnt << " ";
    // 적록 색약 
    for (int i =0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (area[i][j] == 'G') area[i][j] = 'R';
            visit[i][j] = false;
        }
    }
    cnt = 0;
    
    watchArea();
    
    cout << cnt; 
    
    return 0;
}