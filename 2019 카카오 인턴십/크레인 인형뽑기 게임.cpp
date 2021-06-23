#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack <int> bucket;

/*
초반에 문제를 너무 잘못 읽어서 시간을 많이 뺏어먹었다.. 
문제를 잘 보자.. 
matrix를 단순히 다시 생성하지 않아도 x, y 축에 대한 이해만 있으면 위치만 바꿔서 할 수 있다. 
*/

int solution(vector<vector<int>> board, vector<int> moves){
    int answer = 0;
    
    for (int i = 0; i < moves.size(); i++){
        int move = moves[i] - 1;
      
        for (int j = 0; j < board.size(); j++){
            if (board[j][move] != 0){
                if(!bucket.empty()){
                    if (bucket.top() == board[j][move]){
                        bucket.pop();
                        answer += 2; // 사라진 개수를 구하는 문제였음 
                    } else {
                        bucket.push(board[j][move]);
                        
                    }
                } else {
                    bucket.push(board[j][move]);
            
                }
                board[j][move] = 0;
                    break;
            } else continue;
        }
    }
    return answer;
}

int main() {
	/* Test Case */
    vector<vector<int>> board = {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 3},
            {0, 2, 5, 0, 1},
            {4, 2, 4, 4, 2},
            {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    solution(board, moves);
}