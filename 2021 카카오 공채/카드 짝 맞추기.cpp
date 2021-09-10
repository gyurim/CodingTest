#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[5][5] = {-1}; // 초기화 해줘야함 -1이면 무조건 무시하는 조건도 넣어야함 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OOB(int x, int y) {
    return x < 0 || x > 3 || y < 0 || y > 3;
}

void bfs(vector<vector<int>> board, int x, int y) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            visit[i][j] = -1;
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = 0;

    while (!q.empty()) {
        pair<int, int> fnt = q.front();
        x = fnt.first;
        y = fnt.second;
        q.pop();

        // if (board[x][y] == findkey) break;

        for (int i = 0; i < 4; i++) {
            // 방향 
            // 방향키 or ctrl + 방향키
            int nx = x + dx[i] * (i+1);
            int ny = y + dy[i] * (i+1);

            if (!OOB(nx, ny) && board[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                visit[nx][ny] = visit[x][y] + 1;
            } else continue;
        }
    }
    
    
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;

    bfs(board, r, c);

    return answer;
}