#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector <char>matrix[101];
bool visit[101][101];

int n, m;

int xd[] = {0, 0, 1, -1};
int yd[] = {1, -1, 0, 0};

struct Location {
    int x;
    int y;
};

int bfs(){
    int countMatrix[101][101] = {0};
    bool isFind = false;
    queue <Location> q;

    int x = 0;
    int y = 0;
    Location l = {x, y};
    q.push(l);

    if (matrix[x][y] == '0'){
        return 0;
    }
    else {
        countMatrix[x][y] = 1;
        while(!q.empty()){
        	l = q.front();
            x = l.x;
            y = l.y;
            
        	if(x == n-1 && y == m-1)
        		break;
   
            visit[x][y] = true;
            q.pop();

            for (int i = 0; i < 4; i++){
                int nextX = x + xd[i];
                int nextY = y + yd[i];

                if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m){
                    if(matrix[nextX][nextY] == '1' && !visit[nextX][nextY]){
                        l.x = nextX;
                        l.y = nextY;
                        countMatrix[nextX][nextY] = countMatrix[x][y] + 1;
                        visit[nextX][nextY] = true;
                        /*
                        메모리 초과가 났는데, 이 부분이 문제였음 
                        
                        visit[nextX][nextY] = true;

                        바로 true로 해주지 않으면 큐에 여러번 들어가기 때문에 true로 해줘야함! 

                        이것 바꾸니 <<메모리 초과>> 해결됨!
                        */
                        
                        if (nextX == n-1 && nextY == m-1){
                            isFind = true;
                            break;
                        }
                        q.push(l);
                    }
                }
            }
        }     
        return countMatrix[n-1][m-1];
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        char idx[101];
        cin >> idx;
        
        for(int j = 0; j < m; j++){
            matrix[i].push_back(idx[j]);
        }
    }

    cout<<bfs();

    return 0; 
}