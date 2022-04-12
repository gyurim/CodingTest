#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int matrix[101][101] = {0};
int x = 1;
int y = 1;
int n;
queue<pair<int, int>> snakebody;

bool oob (int x, int y) {
    return x < 1 || y < 1 || x > n || y > n;
}

void move(int direct) {
    if (direct == 0) y++;
    else if (direct == 1) x++;
    else if (direct == 2) y--;
    else x--;
}

int main() {
    int k, l;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int ax, ay;
        cin >> ax >> ay;
        matrix[ax][ay] = 2; // apple 
    }
    cin >> l;
    
    vector<pair<int, char>> moving;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        moving.push_back({x, c});
    }

    // snake move 
    int cnt = 0;
    int movingflag = 0;
    int direct = 0; // 0 : 동 / 1 : 남 / 2 : 서 / 3 : 북 
    matrix[1][1] = 1;

    snakebody.push({1, 1});
    
    while (1) {
        cnt++;
        move(direct);
        
        if (oob(x, y)) break;
        if (matrix[x][y] == 1) break;
        if (matrix[x][y] != 2) {
            pair<int, int> tail = snakebody.front();
            matrix[tail.first][tail.second] = 0;
            snakebody.pop();
        } 

        matrix[x][y] = 1;
        snakebody.push({x, y});

        if (moving[movingflag].first == cnt) {
            if (moving[movingflag].second == 'L') {
                direct = (direct + 3) % 4;
            } else {
                direct = (direct + 1) % 4;
            }
            movingflag++;
        }
    }
    cout << cnt;
    return 0;
}