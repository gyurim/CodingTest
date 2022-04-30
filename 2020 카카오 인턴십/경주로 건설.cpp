// 2022.04.30

#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

#define INF 1000000

int n;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
// 좌 우 상 하 

vector<vector<int>> board;
int cost[25][25][4];

struct pos {
    int x, y, cost, dir;
};

bool oob(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= n;
}

void bfs(int x, int y) {
    queue<pos> q;
    q.push({x, y, 0, -1});
    for (int i = 0; i < 4; i++)
        cost[0][0][i] = 0;

    while(!q.empty()) {
        pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) { // 모든 방향에 대해서 값 비교 
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int ncost = cur.cost;
            
            if (!oob(nx, ny)) {
                if (board[nx][ny] == 1) continue;

                if (cur.dir == -1) ncost += 100;
                else if (cur.dir == i) ncost += 100;
                else ncost += 600;
                
                if (ncost < cost[nx][ny][i]) {
                    cost[nx][ny][i] = ncost;
                    q.push({nx, ny, ncost, i});
                }
            }
        }
    }
}

int solution(vector<vector<int>> _board) {
    int answer = 0;
    n = _board.size();
    board = _board;

    // cost 초기화 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++)
                cost[i][j][k] = INF;
    
    bfs(0, 0);
    answer = min(cost[n-1][n-1][0], min(cost[n-1][n-1][1], min(cost[n-1][n-1][2], cost[n-1][n-1][3])));
    return answer;
}

int main() {
    // vector<vector<int>> board {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    // vector<vector<int>> board {{0, 0, 1, 0},{0,0,0, 0}, {0, 1,0,1}, {1, 0,0,0}};
    vector<vector<int>> board {{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}};
    cout << solution(board);
    return 0;
}