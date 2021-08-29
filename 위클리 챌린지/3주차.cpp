#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// table을 bfs 돌려서 하나의 블럭을 find 
// 최대한 많은 조각을 게임 보드에 채워 넣어야함 -> brute force 
// 블럭의 모양과 똑같이 비어있는 칸을 찾아야됨 (회전) 만약에 같은 칸 있으면 확정시키기 

bool visitTable[51][51] = {false};
bool visitBoard[51][51] = {false};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int length = 0;
int paper[51][51];
int gameBoard[51][51];
int _table[51][51];
int answer = 0;
int zeroSize = 0;
int oneSize = 0;

// int startX = 0;
// int startY = 0;
int maxX = 0;
int minX = 52; 
int maxY = 0;
int minY = 52;

bool oom(int a, int b) {
    return a < 0 || a >= length || b < 0 || b >= length;
}

void print() {
    cout << "print() " << endl;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << paper[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // for (int i = 0; i < length; i++) {
    //     for (int j = 0; j < length; j++) {
    //         cout << gameBoard[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

void bfs(int x, int y, int num) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    if (num == 1) {
        paper[x][y] = 1;
        oneSize++;
        visitTable[x][y] = true;
        maxX = x;
        minX = x;
        maxY = y;
        minY = y;
    } else {
        visitBoard[x][y] = true;
        zeroSize++;
    }

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if (num == 1) {
                if (!oom(nextX, nextY) && _table[nextX][nextY] == 1 && !visitTable[nextX][nextY]) {
                    q.push(make_pair(nextX, nextY));
                    visitTable[nextX][nextY] = true;
                    paper[nextX][nextY] = 1;
                    oneSize++;

                    maxX = (maxX < nextX) ? nextX : maxX;
                    maxY = (maxY < nextY) ? nextY : maxY;
                    minX = (minX > nextX) ? nextX : minX;
                    minY = (minY > nextY) ? nextY : minY;
                }
            } else {
                if (!oom(nextX, nextY) && gameBoard[nextX][nextY] == 0 && !visitBoard[nextX][nextY]) {
                    q.push(make_pair(nextX, nextY));
                    visitBoard[nextX][nextY] = true;
                    zeroSize++; 
                }
            }
        }
    }
    // print();
}

void init() {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            paper[i][j] = 0;
            visitBoard[i][j] = false;
        }
    }
    maxX = 0;
    maxY = 0;
    minX = 52;
    minY = 52;
}

bool canAttach(int x, int y) { // game_board의 x, y에 paper를 붙일 수 있는지? 
    // print();
    for (int i = minX; i <= maxX; i++) {
        for (int j = minY; j <= maxY; j++) {
            // paper의 모든 요소를 확인 
            if (paper[i][j] == 1 && gameBoard[x+i-minX][y+j-minY] == 1) return false;
        }
    }
    return true;
}

void attach(int x, int y) {
    cout << minX << " " << maxX << endl;
    cout << minY << " " << maxY << endl;
    for (int i = minX; i <= maxX; i++) {
        for (int j = minY; j <= maxY; j++) {
            if (paper[i][j] == 1) {
                gameBoard[x+i-minX][y+j-minY] = 1;
                answer++;
            }
        }
    }
}

void rotate() {
    cout << "rotate " << endl;
    int tmp[51][51] = {0};
    
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << paper[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            tmp[i][j] = paper[i][j];
        }
    }
   
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << "(" << length-j - minX << " , " << i << ") -> (" <<i << ", " << j << ")" << endl;

            paper[i][j] = tmp[length-j - minX][i];
        }
    }
    
    swap(minX, minY);
    swap(maxX, maxY);
}

void checkAttach() {
    for (int i = 0; i < 4; i++) {
        bool isAttach = false;

        for (int x = 0; x < length; x++) {
            if (isAttach) break;
            for (int y = 0; y < length; y++) {
                if (gameBoard[x][y] == 0) {
                    bfs(x, y, 0);
                    // cout << "zero: " << zeroSize << " one: " << oneSize << endl;
                    if (zeroSize == oneSize) {
                        cout << "x: " << x << " , y: " << y << endl;
                        if (canAttach(x, y)) {
                            isAttach = true;
                            attach(x, y);
                            cout << "attach!" << " x: " << x << " y: " << y << endl;
                            print();
                            zeroSize = 0;
                            break;
                        }
                    }
                    zeroSize = 0;
                }
            }        
        }

        if (isAttach) break;
        rotate();
    }
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    // int answer = -1;
    length = table.size();

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            visitTable[i][j] = false;
            visitBoard[i][j] = false;
            gameBoard[i][j] = game_board[i][j];
            _table[i][j] = table[i][j];
        }
    }   
    
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++) {
            if (table[i][j] == 1 && !visitTable[i][j]) {
                cout << "table x: " << i << " y: " << j << endl;
                // startX = i;
                // startY = j;
                bfs(i, j, 1);
                checkAttach(); // paper에는 기준 스티커가 들어있음 i, j를 굳이? 
                oneSize = 0;
                init();
            }
        }
    }
    cout << answer << endl;
    return answer;
}

int main() {
    vector<vector<int>> game_board;
    vector<vector<int>> table;
    game_board = {
        {1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, 
        {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}
    };
    
    table = {
        {1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}
    };

    solution(game_board, table);
    return 0;
}