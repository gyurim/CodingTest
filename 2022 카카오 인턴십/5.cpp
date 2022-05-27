#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int r, c;

vector<vector<int>> shiftRow(vector<vector<int>> rc) {
    // vector<vector<int>> ans(1005, vector<int>(1005, -1));
    vector<vector<int>> ans(r, vector<int>(c, -1)); // (행, vector<자료형> (열, 초기화 숫자)) : 이차원 백터 초기화 

    for (int i = 0; i < r; i++) {
        if (i == r-1) {
            ans[0] = rc[i]; 
        } else {
            ans[i+1] = rc[i];
        }
    }

    return ans;
}

vector<vector<int>> rotate(vector<vector<int>> rc) {
    // vector<vector<int>> ans(1005, vector<int>(1005, -1));
    vector<vector<int>> ans(r, vector<int>(c, -1));

    int dir[4] = {0, 1, 2, 3}; // 우 하 좌 상 

    for (int i = 0; i < 4; i++) {
        if (i == 0) { // 우 
            for (int j = 0; j < c - 1; j++) {
                ans[0][j+1] = rc[0][j];
            }
        } else if (i == 1) { // 하
            for (int j = 0; j < r - 1; j++) {
                ans[j+1][c-1] = rc[j][c-1];
            }
        } else if (i == 2) { // 좌
            for (int j = c-1; j > 0; j--) {
                ans[r-1][j-1] = rc[r-1][j];
            }
        } else if (i == 3) { // 상
            for (int j = r-1; j > 0; j--) {
                ans[j-1][0] = rc[j][0];
            }
        } 
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || j == 0 || i == r-1 || j == c-1) continue;
            else ans[i][j] = rc[i][j];
        }
    }
    return ans;
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    r = rc.size();
    c = rc[0].size();

    for (auto op : operations) {
        cout << op << endl;
        if (op == "ShiftRow") {
            rc = shiftRow(rc);
        } else if (op == "Rotate") {
            rc = rotate(rc);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << rc[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
    
    return rc;
}

int main() {
    // vector<vector<int>> rc {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<string> operatons {"Rotate", "ShiftRow"};

    vector<vector<int>> rc {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<string> operatons {"ShiftRow", "Rotate", "ShiftRow", "Rotate"};
    solution(rc,operatons);
    return 0;
}