#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// vector<vector<int>> area;
int area[9][9] = {0};
int copyarea[9][9] = {0};
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
 
int bfs(int copyArea[9][9]){
    queue<pair<int, int>> q;
    bool visit[9][9] = {false};

    // 바이러스 전파 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copyArea[i][j] == 2) {
                for (int h = 0; h < 4; h++) {
                    int nextX = i + dx[h];
                    int nextY = j + dy[h];

                    if (copyArea[nextX][nextY] == 0 && nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
                        copyArea[nextX][nextY] = 2;
                }
            }
        }
    }

    //안전지대 구하기 
    int count = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m ; j++){
            if (copyArea[i][j] == 0 && !visit[i][j]) {
                q.push(make_pair(i, j));
                visit[i][j] = true;
                count++;

                while(!q.empty()) {
                    pair<int, int> front = q.front();
                    q.pop();

                    for (int h = 0; h < 4; h++) {
                        int nextX = i + dx[h];
                        int nextY = j + dy[h];

                        if (copyArea[nextX][nextY] == 0 && !visit[nextX][nextY]) {
                            visit[nextX][nextY] = true;
                            q.push(make_pair(nextX, nextY));
                            count++;
                        }
                    }
                }
            }
        }
    }
    
    cout << "count: " << count << endl;

    return count;
}

// int setSafeWall(int n, int m){
//     int copyArea[9][9] = {0};
//     vector<int> answer;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             copyArea[i][j] = area[i][j];
//         }
//     }
    
//     int count = 0;
    
//     for (int j = 0; j < n; j++){
//         for (int h = 0; h < m; h++) {
            
//             if (copyArea[h][j] == 0) {
//                 copyArea[h][j] = 1;
//                 count++;
//             }
            
//             if (count == 3) {
//                 answer.push_back(bfs(copyArea, n, m));
//             }
//         }
//     }

    

//     sort(answer.begin(), answer.end());
    
//     return answer[answer.size()-1];
// }

int setSafeWall(int count){
    int copyArea[9][9] = {0};
    vector<int> answer;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copyArea[i][j] = area[i][j];
        }
    }
    
    int count = 0;
    
    for (int j = 0; j < n; j++){
        for (int h = 0; h < m; h++) {
            
            if (copyArea[h][j] == 0) {
                copyArea[h][j] = 1;
                count++;
            }
            
            if (count == 3) {
                answer.push_back(bfs(copyArea, n, m));
            }
        }
    }

    sort(answer.begin(), answer.end());
    
    return answer[answer.size()-1];
}

int main(){
    int n, m = 0;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> area[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (area[i][j] == 0) {
                setSafeWall(0);
            }
        }
    }

    return 0;
}