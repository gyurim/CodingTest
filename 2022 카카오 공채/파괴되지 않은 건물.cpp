#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int state[1005][1005] = {0}; // 변화량 테이블 
    fill(&state[0][0], &state[1004][1004], 0);

    int answer = 0;
    
    // skill의 개수 : 250,000 
    // 따라서 (r1, c1) ~ (r2, c2) 범위 내의 모든 값을 변경해주면 시간 초과 발생 
    // 따라서 모든 범위가 아니라 4개의 부분만 바꿔줘 시간을 줄여야 됨. 

    for (auto sk : skill) { 
        int type = sk[0];
        int r1 = sk[1], c1 = sk[2], r2 = sk[3], c2 = sk[4];
        int degree = sk[5];

        if (type == 1) degree = -degree;

        state[r1][c1] += degree;
        state[r1][c2 + 1] -= degree;
        state[r2 + 1][c1] -= degree;
        state[r2 + 1][c2 + 1] += degree;
    }

    // 누적합 처리 
    int n = board.size();
    int m = board[0].size();

    for (int i = 1; i < n; i++) 
        for (int j = 0; j < m; j++) 
            state[i][j] += state[i-1][j];

    for (int i = 0; i < n; i++) 
        for (int j = 1; j < m; j++) 
            state[i][j] += state[i][j-1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + state[i][j] > 0) answer++;
        }
    }  
    return answer;
}

int main() {
    vector<vector<int>> board;
    vector<int> vec {5,5,5,5,5};
    board.push_back(vec);
    board.push_back(vec);
    board.push_back(vec);
    board.push_back(vec);

    vector<vector<int>> skill; // type, r1, c1, r2, c2, degree 
    vec = {1,0,0,3,4,4};
    skill.push_back(vec);
    vec = {1,2,0,2,3,2};
    skill.push_back(vec);
    vec = {2,1,0,3,1,2};
    skill.push_back(vec);
    vec = {1,0,1,3,3,1};
    skill.push_back(vec);

    cout << solution(board, skill);
    return 0;
}