#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isCheck[100][100];

int bfs (int x, int y, vector<vector<int>> picture, int m, int n) {
    queue <pair<int, int>> q;
    int count = 1;
    isCheck[x][y] = true;

    q.push(make_pair(x, y));

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextx = front.first + dx[i];
            int nexty = front.second + dy[i];

            if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
                if (!isCheck[nextx][nexty] && picture[x][y] == picture[nextx][nexty]){
                    q.push(make_pair(nextx, nexty));
                    isCheck[nextx][nexty] = true;
                    count++;
                }   
            }
        }
    }
    return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            isCheck[i][j] = false;
        }
    }
    
    // bfs
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!isCheck[i][j] && picture[i][j] != 0) {
                int count = bfs(i, j, picture, m, n);
                number_of_area++;

                max_size_of_one_area = (max_size_of_one_area <= count ? count : max_size_of_one_area);
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    solution(6, 4, matrix);
}