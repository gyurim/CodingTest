#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;
char boards[31][31];

int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

int M, N;

bool oob(int x, int y) {
    return x < 0 || y < 0 || x >= M || y >= N;
}

int solution(int m, int n, vector<string> board) {  
    M = m, N = n;
    int answer = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            boards[i][j] = board[i][j];
        }
    }

    set<pair<int,int>> idx;

    while (true) {
        // 4 블록 find 
        bool canRotate = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char cur = boards[i][j];
                int cnt = 0;

                if (cur == ' ') continue;
                if (cur < 'A' || cur > 'Z') continue;
                
                for (int k = 0; k < 4; k++) {
                    int kx = i + dx[k];
                    int ky = j + dy[k];

                    if (!oob(kx, ky) && cur == boards[kx][ky])
                        cnt++;
                }

                if (cnt == 4) {
                    canRotate = true;
                    
                    for (int k = 0; k < 4; k++) {
                        int kx = i + dx[k];
                        int ky = j + dy[k];

                        idx.insert({kx, ky});
                    }
                }
            }
        }
        
        if (!canRotate) break; // 4개의 블록 찾지 못함 
        
        for (auto i : idx) {
            int x = i.first;
            int y = i.second;

            boards[x][y] = ' ';
            answer++;
        }

        idx.clear(); // set 초기화

        
        for (int i = 0; i < n; i++) {
            vector<int> vec;
            for (int j = m - 1; j >= 0; j--) {
                if (boards[j][i] != ' ') 
                    vec.push_back(boards[j][i]);
            }
            
            while(vec.size() < m) {
                vec.push_back(' ');
            }
            
            for (int j = 0; j < m; j++) {
                boards[m-1-j][i] = vec[j];
            }
        }
    }
    // cout << answer;
    return answer;
}
/*
// 예외 1 
AABBEE
AAAEEE
VAAEEV
AABBEE
AACCEE
VVCCEE
답: 32
*/

/*
AA
BB
AA
BB
ZZ
ZZ
CC
답: 4
*/

int main(){
    vector<string> vec {"ABCD","BACE","BCDD","BCDD"};
    solution(4, 4, vec);
    return 0;
}