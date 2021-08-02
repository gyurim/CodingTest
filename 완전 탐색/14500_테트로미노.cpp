#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500;

typedef struct {
    int x, y;
} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M;
int cell[MAX][MAX];
bool visited[MAX][MAX];

bool OOB(int x, int y) {
    return (x < 0 || x >= N || y < 0 || y >= M);
}

int dfs(int x, int y, int cnt) {
    if (cnt == 4) 
        return cell[x][y];
    
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        int nextX = x + moveDir[i].x;
        int nextY = y + moveDir[i].y;

        if (!OOB(x, y) && !visited[nextX][nextY]) {
            visited[nextX][nextY] = true;
            sum = max(sum, cell[x][y] + dfs(nextX, nextY, cnt + 1));
            visited[nextX][nextY] = false; // 꼭 처리해야함 
        }
    }
    return sum;
}

int middleFinding(int x, int y) {
    int result = 0;
    // ㅗ
    if (y >= 1 && x >= 1 && x < M-1) 
        result = max(result, cell[x][y-1] + cell[x][y] + cell[x-1][y] + cell[x][y-1]);
    // ㅏ
    if (y >= 1 && y < N-1 && x < M-1) 
        result = max(result, cell[x-1][y] + cell[x][y] + cell[x][y+1] + cell[x+1][y]);
    // ㅜ
    // ㅓ
}

int main() {

}

// #include <iostream>
// #include <utility>
// #include <cmath>

// using namespace std;
// int n, m;
// int paper[501][501];

// int type1[2][5] = {{1, 1, 1, 1}};
// int type2[3][3] = {{1, 1}, {1, 1}};
// int type3[4][3] = {{1, 0}, {1, 0}, {1, 1}};
// int type4[3][3] = {{1, 0}, {1, 1}, {0, 1}};
// int type5[3][4] = {{1, 1, 1}, {0, 1, 0}}; 

// int type[5][5];
// int r, c;

// void rotate() {
//     int tmp[5][5];

//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++) {
//             tmp[i][j] = type[i][j];
//         }
//     }

//     for (int i = 0; i < c; i++) {
//         for (int j = 0; j < r; j++) {
//             type[i][j] = tmp[r-j-1][i];
//         }
//     }
//     swap(r, c);
// }

// void mirror() {
//     int tmp[5][5];
//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++) {
//             tmp[i][j] = type[i][j];
//         }
//     }

//     for (int i = 0; i < r; i++){
//         for (int j = 0; j < c; j++) { // c = 3 
//             type[i][j] = tmp[i][c-j-1];
//         }
//     }
// }

// void upmirror() {
//     int tmp[5][5];
//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++) {
//             tmp[i][j] = type[i][j];
//         }
//     }

//     for (int i = 0; i < r; i++){ // r = 3
//         for (int j = 0; j < c; j++) { // c = 2
//             type[i][j] = tmp[r-i-1][j];
//         }
//     }
// }

// void setType(int typeNum) {
//     if (typeNum == 1) {
//         r = 1;
//         c = 4;
//         for (int i = 0; i < 5; i++) {
//             for (int j = 0; j < 5; j++) {
//                 type[i][j] = type1[i][j];
//             }
//         }
//     } else if (typeNum == 2) {
//         r = 2;
//         c = 2;
//         for (int i = 0; i < 5; i++) {
//             for (int j = 0; j < 5; j++) {
//                 type[i][j] = type2[i][j];
//             }
//         }
//     } else if (typeNum == 3) {
//         r = 3;
//         c = 2;
//         for (int i = 0; i < 5; i++) {
//             for (int j = 0; j < 5; j++) {
//                 type[i][j] = type3[i][j];
//             }
//         }
//     } else if (typeNum == 4) {
//         r = 3;
//         c = 2;
//         for (int i = 0; i < 5; i++) {
//             for (int j = 0; j < 5; j++) {
//                 type[i][j] = type4[i][j];
//             }
//         }
//     } else  {
//         r = 2;
//         c = 3;
//         for (int i = 0; i < 5; i++) {
//             for (int j = 0; j < 5; j++) {
//                 type[i][j] = type5[i][j];
//             }
//         }
//     }
// }

// int attach(int x, int y) {
//     int sum = 0; 

//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++) {
//             if (type[i][j] == 1) {
//                 sum += paper[x+i][y+j];
//             }
//         }
//     }
//     return sum;
// }

// int main() {  
//     int output = 0;
//     cin >> n >> m;
    
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> paper[i][j];
//         }
//     }

//     for (int i = 1; i <= 5; i++) {
//         setType(i);

//         for (int j = 0; j < 12; j++) {
//             for (int x = 0; x <= n-r; x++) {
//                 for (int y = 0; y <= m-c; y++) {
//                     output = max(output, attach(x, y));
//                 }
//             }

//             if (j % 3 == 0) rotate();
//             else if (j % 3 == 1 && (i == 3 || i == 4)) mirror();
//             else if (j % 3 == 2 && (i == 3 || i == 4)) upmirror();
//         }
//     }
//     cout << output;
//     return 0;
// }