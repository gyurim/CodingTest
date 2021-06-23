#include <iostream>
#include <queue>

using namespace std;

bool land[51][51] = {false};
bool visit[51][51] = {false};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int landX, landY = 0;

struct location {
    int x;
    int y;
};

void bfs(int currentX, int currentY){
    queue<location> q;

    visit[currentX][currentY] = true;
    location l = {currentX, currentY};
    q.push(l);

    while(!q.empty()){
        l = q.front();
        currentX = l.x;
        currentY = l.y;
        
        q.pop();

        for (int i = 0; i < 4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX >= 0 && nextX < landX && nextY >= 0 && nextY < landY){
                if (land[nextX][nextY] && !visit[nextX][nextY]){
                    visit[nextX][nextY] = true;
                    l = {nextX, nextY};
                    q.push(l);
                }
            }
        }
    }
}

int chekLand(){
    int count = 0;
    for(int i = 0; i < landX; i++){
        for (int j = 0; j < landY; j++){
            if (land[i][j] && !visit[i][j]){
                bfs(i, j);
                count++;
            }
        }
    }
    return count;
}

void initLand(){
    for (int i = 0; i < landX; i++){
        for(int j = 0; j < landY; j++){
            land[i][j] = false;
            visit[i][j] = false;
        }
    }  
}

int main(){
    int testCase;
    cin >> testCase;

    while(testCase > 0){
        testCase--;

        int k;
        cin >> landX >> landY >> k;

        while (k > 0){
            k--;
            int x, y;
            cin >> x >> y;
            land[x][y] = true;
        }

        cout << chekLand() << "\n";
        initLand();
    }
}