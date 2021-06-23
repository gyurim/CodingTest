#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

int main(){
    string answer = "";
    int n, k;
    cin >> n >> k;
    vector <string> cmd = {"D 1", "C", "Z"};

    vector<int> matrix;
    vector <pair<int, int>> erase;

    for (int i = 0; i < n; i++){
        matrix.push_back(i);
    } 

    for (int i = 0; i<cmd.size(); i++){
        char op[4];
        strcpy(op, cmd[i].c_str());

        if (op[0] == 'D'){ // down
            int cnt = op[2] - '0';

            if (k + cnt < matrix.size()){ // 3항 연산자로 바꾸기 
                k += cnt;
            } else {
                k = matrix.size()-1;
            }

        } else if (op[0] == 'U') { // up
            int cnt = op[2] - '0';

            if (k - cnt >= 0){ // 3항 연산자로 바꾸기 
                k -= cnt;
            } else {
                k = 0;
            }

        } else if (op[0] == 'Z') { // 최근 삭제 복구
            if (erase.size() > 0){
                pair<int, int> p = erase[erase.size()-1];

                matrix.insert(matrix.begin() + p.first, p.second);
                erase.pop_back();

                if (p.first <= k){
                    k += 1;
                }
            }

        } else if (op[0] == 'C') { // 선택된 항 삭제 후 아래 행 선택 혹은 윗 행 선택 
            erase.push_back(make_pair(k, matrix[k]));
            matrix.erase(matrix.begin() + k);

            if ( k == matrix.size())
                k -= 1;
        }
    }

    int cnt = 0;

    if (matrix.size() == 0){
        for (int i = 0; i < n; i++){
            answer += 'X';
        }
    } else {
        for (int i = 0; i < n; i++){
            if (cnt <= matrix.size()-1 && i == matrix[cnt]) {
                answer += 'O';
                cnt++;
            } else {
                answer += 'X';
            }
        }   
    }
    
    for (int i = 0; i < matrix.size(); i++)
        cout << matrix[i] << " ";

    cout << endl << answer;

    return 0;
}