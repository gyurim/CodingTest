#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    int snail[1001][1001] = {0};
    int num = 1;
    int x = -1;
    int y = 0;

    int first, second = -1;

    if ( n % 3 == 0) {
        first = 0;
        second = 2;
        // third = 1;
    } else if (n % 3 == 1){
        first = 1;
        second = 0;
        // third = 2;
    } else {
        first = 2;
        second = 1;
        // third = 0;
    }


    for(int i = n; i > 0; i--){
        if (i % 3 == first) {
            for (int j = 0; j < i; j++){
                x += 1;
                snail[x][y] = num;
                num += 1;
            }
        } else if (i % 3 == second) {
            for (int j = 0; j < i; j++){
                y += 1;
                snail[x][y] = num;     
                num += 1;
            }
        } else {
            for (int j = 0; j < i; j++){
                x -= 1;
                y -= 1;
                snail[x][y] = num;
                num += 1;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (snail[i][j] != 0){
                answer.push_back(snail[i][j]);
            } else break;
        }
    }

    return answer;
}