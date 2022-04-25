// 2022.04.23
// 다시 풀기 

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[21]; // {m-1, m-2, .. , 1, 0} 
int n, m, k; // lock size, key size, board size 

vector<vector<int>> rotate(vector<vector<int>> key) {
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = key[m - j - 1][i];
        }
    }
    return temp;
}

bool isUnlock(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    // 판에 key를 더함 
    for (int i = x; i < x + m; i++) {
        for (int j = y; j < y + m; j++) {
            board[i][j] += key[i-x][j-y];
        }
    }
    // 풀렸는지 
    for (int i = m - 1; i <= k - m; i++) {
        for (int j = m - 1; j <= k - m; j++) {
            if (board[i][j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    m = key.size();
    n = lock.size();

    k = n + (m-1) * 2; 
    vector<vector<int>> board(k, vector<int>(k, 0));

    // 판에 자물쇠 위치 시킴
    for (int i = m - 1; i <= k - m; i++) 
        for (int j = m - 1; j <= k - m; j++) 
            board[i][j] = lock[i-m+1][j-m+1];
    
    // x, y 한 칸씩 이동하면서 풀렸는지 안풀렸는지 체크 
    for (int r = 0; r < 4; r++) {
        for (int i = 0; i <= k - m; i++) {
            for (int j = 0; j <= k - m; j++) {
                if (isUnlock(i, j, key, board))
                    return true;
            }
        }
        key = rotate(key);
    }
    return answer;
}

int main(){

    vector<vector<int>> key;
    vector<int> vec;
    string s = "[[0, 0, 0], [1, 0, 0], [0, 1, 1]]";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (s[i-1] == '[') {
                if (i-1 != 1) 
                    key.push_back(vec);
                vec.clear();
                vec.push_back(s[i] - '0');
            } else vec.push_back(s[i] - '0');
        }
    }
    key.push_back(vec);
    vec.clear();
    vector<vector<int>> lock;
    s = "[[1, 1, 1], [1, 1, 0], [1, 0, 1]]";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (s[i-1] == '[') {
                if (i-1 != 1) 
                    lock.push_back(vec);
                vec.clear();
                vec.push_back(s[i] - '0');
            } else vec.push_back(s[i] - '0');
        }
    }
    lock.push_back(vec);
    cout << solution(key, lock);
}