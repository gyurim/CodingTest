#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; 
int board[21][21];
int copyBoard[21][21];

void rotate() {
    int tmp[21][21];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = copyBoard[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copyBoard[i][j] = tmp[n-j-1][i];
        }
    }
}

// 서쪽으로 쏠리게 한 다음 
// 북 -> 90도 회전
// 동 -> 180도 회전
// 남 -> 270도 회전
// 서 -> 0도 회전 

void merge(int dir){
    while(dir--) rotate();

    for (int i = 0; i < n; i++) {
        int tilted[21] = {};
        int idx = 0;

        for(int j = 0; j < n; j++) {
            if (copyBoard[i][j] == 0) continue;
            if (tilted[idx] == 0) tilted[idx] = copyBoard[i][j];
            else if (tilted[idx] == copyBoard[i][j]) {
                tilted[idx++] *= 2;
            } else {
                tilted[++idx] = copyBoard[i][j];
            }
        }

        for (int j = 0; j < n; j++) 
            copyBoard[i][j] = tilted[j];
    }
}

// void incline() {
//     int arr[] = {0, 2, 0, 2, 8, 8, 0, 16};
//     int tilted[8] = {};
//     int idx = 0;

//     for (int i = 0; i < 8; i++) {
//         if (arr[i] == 0) continue;
//         if (tilted[idx] == 0) tilted[idx] = arr[i];
//         else if (tilted[idx] == arr[i]) {
//             tilted[idx++] *= 2;
//         } else 
//             tilted[++idx] = arr[i];
//     }
// }

int main() {  
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int maxNum = 0;

    for (int i = 0; i < (1<<2*5); i++) {
        int tmp = i;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) 
                copyBoard[r][c] = board[r][c];
        }
        
        for (int j = 0; j < 5; j++) {
            int dir = tmp % 4;
            merge(dir);
            tmp /= 4;
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                maxNum = max(maxNum, copyBoard[r][c]);
            }
        }
    }
    cout << maxNum;
    return 0;
}