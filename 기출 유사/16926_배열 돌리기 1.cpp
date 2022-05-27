#include <iostream>
#include <cstring>
using namespace std;

int map[305][305];
int rotated[305][305];
int n, m, r;

void func() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = rotated[i][j];
        }
    }
}

void rotate() {
    int mid_n = n / 2;
    int mid_m = m / 2;
    int mid = min(mid_n,mid_m);
    
    memset(rotated, 0, sizeof(rotated));
    
    int end_x = n, end_y = m;
    
    for (int i = 0; i < mid; i++) {
        int x = i, y = i;
        
        for (int dir = 0; dir < 4; dir++) {
            if (dir == 0) { // 하 
                while(x < end_x - 1) {
                    // cout << x+1 << " " << y << endl;
                    rotated[x+1][y] = map[x][y]; 
                    x++;
                }
            } else if (dir == 1) { // 우
                while(y < end_y - 1) {
                    rotated[x][y+1] = map[x][y];
                    y++;
                }
            } else if (dir == 2) { // 상
                while (x > i) {
                    rotated[x-1][y] = map[x][y];
                    x--;
                }
                
            } else if (dir == 3) { // 좌 
                while(y > i) {
                    rotated[x][y-1] = map[x][y];
                    y--;
                }
            }
        }
        end_x -= 1;
        end_y -= 1;
    }
    // map = rotated 대입
    func();
}

int main() {
    cin >> n >> m >> r;
    memset(map, 0, sizeof(map));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    while (r--) {
        rotate();
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}