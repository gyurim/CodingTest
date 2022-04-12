#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int map[26][26];
bool isVisit[26][26];
vector<int> homeCnt;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool oob(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= n;
}

int bfs(int x, int y) {
    int danziCnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    isVisit[x][y] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!oob(nx, ny) && map[nx][ny] == 1 && !isVisit[nx][ny]) {
                q.push(make_pair(nx, ny));
                isVisit[nx][ny] = true;
                danziCnt++;
            }
        }
    }
    return danziCnt;
}

int main() {
    
    cin >> n;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        
        for (int j = 0; j < n; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!isVisit[i][j] && map[i][j] == 1) {
                homeCnt.push_back(bfs(i, j));
                cnt++;
            }
        }
    }

    sort(homeCnt.begin(), homeCnt.end());
    cout << cnt << endl;
    for (int i = 0; i < homeCnt.size(); i++) {
        cout << homeCnt[i] << endl;
    }
    return 0;
}