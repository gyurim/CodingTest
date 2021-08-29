#include <utility>
#include <iostream>

using namespace  std;

int n, m;
int r, c;
int note[42][42];
int paper[12][12];

void attach(int x, int y){
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (paper[i][j] == 1) note[x+i][y+j] = 1;
        }
    }
}

bool pastable(int x, int y){
    // 스티커를 특정 영역에 붙일 수 있는지 확인하고 붙이기
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (paper[i][j] == 1 && note[x+i][y+j] == 1) return false;
        }
    }
    return true;
}

void rotate(){
    int tmp[12][12];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = paper[i][j];
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            paper[i][j] = tmp[r-j-1][i];
        }
    }
    swap(r, c); // utility 헤더 
}

int main() {
    int k;
    cin >> n >> m >> k;

    while (k--) {
        cin >> r >> c;
        for(int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> paper[i][j];
            }
        }

        // 붙일 수 있는 곳이 있는지 확인한 후, 자리가 없다면 90도 회전 
        for (int rot = 0; rot < 4; rot++) {
            bool is_paste = false; // 붙이는 것 성공? 실패?
            for(int x = 0; x <= n-r; x++) { 
                // n = 7 r = 5인 경우, 모눈종이의 0, 1, 2에만 스티커 붙일 수 있음 
                // 인덱스 설정 제일 중요! 
                if (is_paste) break;
                for(int y = 0; y <= m-c; y++) {
                    if (pastable(x, y)) {
                        is_paste = true;
                        attach(x, y);
                        break;
                    }
                }
            }
            if (is_paste) break;
            // 붙일 수 없다면 회전해서 다시 0, 0부터 확인 
            rotate();
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cnt += note[i][j];
    }
    cout << cnt;
    return 0;
}

// #include <iostream>
// #include <utility>

// using namespace std;
// int n, m, k;
// int r, c;
// int notebook[42][42];
// int sticker[12][12];

// void rotate() {
//     int tmp[12][12]; 
//     for(int i = 0; i < r; i++)
//         for (int j = 0; j < c; j++) 
//             tmp[i][j] = sticker[i][j];
    
//     for (int i = 0; i < c; i++) {
//         for (int j = 0; j < r; j++) {
//             sticker[i][j] = tmp[r-j-1][i];
//         }
//     }
//     swap(r, c);
// }

// bool attach(int x, int y) {
//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++) {
//             if (sticker[i][j] == 1 && notebook[i+x][j+y] == 1) return false;
//         }
//     }

//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++) {
//             if (sticker[i][j] == 1) 
//                 notebook[x+i][y+j] = 1;
//         }
//     }
//     return true;
// }

// int main() {
//     cin >> n >> m >> k;
    
//     while (k--) {
//         cin >> r >> c;
//         for (int i = 0; i < r; i++) 
//             for (int j = 0; j < c; j++)
//                 cin >> sticker[i][j];
        
//         for (int i = 0; i < 4; i++) {
//             bool canAttach = false;

//             for (int x = 0; x <= n-r; x++) {
//                 for (int y = 0; y <= m-c; y++) {
//                     if (attach(x, y)) {
//                         canAttach = true;
//                         break;
//                     }
//                 }
//                 if (canAttach) break;
//             }
//             if (canAttach) break;
//             rotate();
//         }
//     }

//     int cnt = 0;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cnt += notebook[i][j];
//         }
//     }
//     cout << cnt;
//     return 0;
// }