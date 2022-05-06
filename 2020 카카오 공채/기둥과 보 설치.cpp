// 2022.05.06
// 틀렸음 다시 풀기
// 한 개의 index 안에 기둥과 보가 둘 다 들어갈 수 있음 -> 문제 이해 잘못함 ㅠ

#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

#define delete 0
#define install 1
#define column 0 // 기둥 
#define girder 1 // 보 

int matrix[101][101];

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    memset(matrix, -1, sizeof(matrix));
    
    for (auto frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2]; // 0: 기둥, 1: 보
        int b = frame[3]; // 0: 삭제, 1: 설치 

        // 보는 오른쪽 방향으로 삭제 및 설치, 기둥은 왼쪽 방향 
        if (a == column) { // 기둥 
            // 바닥 위에 있어야함 
            if (b == delete) { // 삭제 
                if (matrix[x][y] != 0) continue;
                // 삭제 안 되는 조건 
                // x-1, y+1 와 x, y+1 이 보의 조건 맞으면 됨 
                if ((x > 0 && matrix[x-1][y+1] == 1) && matrix[x][y+1] == 1) {
                    matrix[x][y] = -1;
                    continue;
                }
                if (x > 0 && matrix[x-1][y+1] == 1 && matrix[x-1][y] == 0) {
                    matrix[x][y] = -1;
                    continue;
                }
                if (matrix[x][y+1] == 1 && matrix[x+1][y] == 0) {
                    matrix[x][y] = -1;
                    continue;
                }
            } else if (b == install) { // 설치 
                if (matrix[x][y] != -1) continue;
                // 조건 
                if (y == 0) matrix[x][y] = 0;
                if (x > 0 && matrix[x-1][y] == 1) matrix[x][y] = 0;
                if (y > 0 && matrix[x][y-1] == 0) matrix[x][y] = 0;
            }
        } else if (a == girder) { // 보 
            if (b == delete) { // 삭제 
                if (matrix[x][y] != 1) continue;
                if (matrix[x+1][y] == 1 && (y > 0 && matrix[x+1][y-1] == 0)) continue;
                if ((x > 0 && matrix[x-1][y] == 1) && matrix[x-1][y-1] == 0) continue;
                matrix[x][y] = -1;
            } else if (b == install) { // 설치 
                if (matrix[x][y] != -1) continue;
                // 조건 
                if (y > 0 && matrix[x+1][y-1] == column) matrix[x][y] = 1;
                if (y > 0 && matrix[x][y-1] == column) matrix[x][y] = 1; 
                if ((x > 0 && matrix[x-1][y] == 1) && matrix[x+1][y] == 1) matrix[x][y] = 1; 
            }
        }
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (matrix[i][j] == 1 || matrix[i][j] == 0)
                answer.push_back({i, j, matrix[i][j]});
        }
    }
    return answer;
}

int main(){
    string s = "[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]";
    vector<vector<int>> build_frame;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            int j = i + 1;
            vector<int> vec;
            string number = "";
            while(s[j] != ']') {
                if (s[j] >= '0' && s[j] <= '9') {
                    number += s[j];
                } else if (s[j] == ',') {
                    vec.push_back(atoi(number.c_str()));
                    number = "";
                }
                j++;
            }
            vec.push_back(atoi(number.c_str()));
            number = "";
            i = j;
            build_frame.push_back(vec);
        }
    }
    solution(5, build_frame);
    return 0;
}