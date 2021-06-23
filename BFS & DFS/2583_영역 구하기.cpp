#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int m, n;
int matrix[101][101] = {0}; 
bool isVisit[101][101] = {false};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

int bfs(){
    int cnt = 1;

    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = front.first + dx[i];
            int nextY = front.second + dy[i];

            if (matrix[nextX][nextY] == 0 && !isVisit[nextX][nextY]){
                if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                    q.push(make_pair(nextX, nextY));
                    isVisit[nextX][nextY] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main(){
    int k;
    cin >> m >> n >> k;

    vector <int> answer;

    for (int i = 0; i < k; i++) {
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;

        for (int j = startY; j < endY; j++) {
            for (int h = startX; h < endX; h++) {
                matrix[j][h] = 1;
            }
        }
    }
    int bfs_cnt = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0 && !isVisit[i][j]) {
                q.push(make_pair(i, j));
                isVisit[i][j] = true;
                answer.push_back(bfs());
                bfs_cnt++;
            }
        }
    }
    cout << bfs_cnt << endl;
    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}