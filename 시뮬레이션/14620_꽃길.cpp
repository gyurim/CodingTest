#include <iostream>
#include <cstring>
using namespace std;

int n;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int garden[15][15];

bool visited[20][20] = {false};

bool oob(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= n;
}

int minCost = 2000000;

void func(int k) {
    if (k == 3) {
        int cost = 0;
        // cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) cost += garden[i][j];
                // cout << visited[i][j] << " ";
            }
            // cout << endl;
        }
        
        minCost = min(minCost, cost);
        
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool canBloom = false;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                
                if (oob(nx, ny)) break; // 이거 틀렸을 수도 있음 체크 
                if (visited[nx][ny]) break;
                
                if (dir == 3) canBloom = true;
            }
            
            if (!canBloom) continue;
            // 씨앗 부분도 방문 처리 
            visited[i][j] = true;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                
                visited[nx][ny] = true;
            }
            
            func(k+1);
            
            visited[i][j] = false;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                
                visited[nx][ny] = false;
            }
        }
    }
}

int main(){  
    cin >> n;
    memset(garden, 0, sizeof(garden));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> garden[i][j];
        }
    }  
    
    // 씨앗의 개수 : 3 
    func(0);
    cout << minCost;
    return 0;
}