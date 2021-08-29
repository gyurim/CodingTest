#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int length = 0;
bool visitTable[52][52] = {false};
bool visitBoard[52][52] = {false};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int gameBoard[52][52] = {0};
int answer = 0;

int mx = 0;
int my = 0;

int currentPieceSize = 0;
int crow = 0;
int ccol = 0;

bool OOB(int x, int y) {
    return x < 0 || x >= length || y < 0 || y >= length;
}

vector<vector<int>> tablebfs(int x, int y, vector<vector<int>> table) {
    currentPieceSize = 1;
    
    int minX = x;
    int minY = y;
    int maxX = x;
    int maxY = y;

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visitTable[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (!OOB(nextX, nextY) && !visitTable[nextX][nextY] && table[nextX][nextY] == 1) {
             
                visitTable[nextX][nextY] = true;
                q.push(make_pair(nextX, nextY));

                minX = (minX > nextX) ? nextX : minX;
                minY = (minY > nextY) ? nextY : minY;
                maxX = (maxX < nextX) ? nextX : maxX;
                maxY = (maxY < nextY) ? nextY : maxY;

                currentPieceSize++;
            }
        }
    }

    vector<vector<int>> ctable;
    crow = maxX - minX;
    ccol = maxY - minY;

    for (int i = minX; i <= maxX; i++) {
        vector<int> row;
        for (int j = minY; j <= maxY; j++) {
            row.push_back(table[i][j]);
        }
        ctable.push_back(row);
    }
    
    return ctable;
}

int boardbfs(int x, int y) {
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visitBoard[x][y] = true;

    mx = x;
    my = y;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (!OOB(nextX, nextY) && !visitBoard[nextX][nextY] && gameBoard[nextX][nextY] == 0) {
                q.push(make_pair(nextX, nextY));
                visitBoard[nextX][nextY] = true;
                mx = (mx > nextX) ? nextX : mx;
                my = (my > nextY) ? nextY : my;
                cnt++;
            }
        }
    }
    return cnt;
}

bool checkBoundary(int x, int y, vector<vector<int>> ctable) {
    
    for (int i = 0; i < ctable.size(); i++) {
        for (int j = 0; j < ctable[i].size(); j++) {
            if (gameBoard[mx + i][my + j] == 1 && ctable[i][j] == 1) return false;
        }
    }
    return true;
}

vector<vector<int>> rotate(vector<vector<int>> ctable) {
    vector<vector<int>> rotateTable;
    int tmp[52][52] = {0};
    int rows = ctable.size();
    int cols = ctable[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tmp[i][j] = ctable[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        vector<int> row;
        for (int j = 0; j < rows; j++) {
            row.push_back(tmp[rows-j-1][i]);
        }
        rotateTable.push_back(row);
    }
    swap(ccol, crow);
    return rotateTable;  
}

void attach(int x, int y, vector<vector<int>> ctable) {
    answer += currentPieceSize;
    for (int i = 0; i < ctable.size(); i++) {
        for (int j = 0; j < ctable[i].size(); j++) {
            gameBoard[x+i][y+j] = 1;
        }
    }
}

void init() {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            visitBoard[i][j] = false;
        }
    }
}

void checkAttach(vector<vector<int>> ctable) {
    for (int cnt = 0; cnt < 4; cnt++) {
        bool canAttachFlag = false;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (gameBoard[i][j] == 0) {
                    if (currentPieceSize == boardbfs(i, j)) {
                        // i j 가 아니라 minx miny game_board의 
                        if (checkBoundary(i, j, ctable)) {
                            canAttachFlag = true;
                            attach(i, j, ctable);
       
                            break;
                        }
                    }
                }
            }
            if (canAttachFlag) break;
        }
        if (canAttachFlag) break;
        ctable = rotate(ctable);
        init();
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    length = table.size();

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            gameBoard[i][j] = game_board[i][j];
        }
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (table[i][j] == 1 && !visitTable[i][j]) {
                vector<vector<int>> ctable = tablebfs(i, j, table);
                checkAttach(ctable);
                currentPieceSize = 0;
                init();
            }
        }
    }

    cout << answer;
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