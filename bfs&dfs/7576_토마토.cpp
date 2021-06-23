#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int box[1001][1001] = {-1};
int count = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct location {
    int x;
    int y;
};

queue<location> q;
queue<location> nextTomato;

void bfs(){
    while(!nextTomato.empty()){
        location l = nextTomato.front();
        q.push(l);
        nextTomato.pop();
    }

    while(!q.empty()){
        location l = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int nextX = l.x + dx[i];
            int nextY = l.y + dy[i];

            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m){
               if (box[nextX][nextY] == 0) {
                   l = {nextX, nextY};
                   box[nextX][nextY] = 1;
                   nextTomato.push(l);
               } 
            }
        }
    }
    
    if (!nextTomato.empty())
        count++;
}

int main(){
    cin >> m >> n;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> box[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (box[i][j] == 1) {
                location l = {i, j};   
                nextTomato.push(l);
            }
        }
    }

    while(!nextTomato.empty()){
        bfs();
        // count++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (box[i][j] == 0) 
                count = -1;
        }
    }
    
    cout << count;
    
    return 0;
}