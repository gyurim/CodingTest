#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> _info;
vector<vector<int>> trees(18);
bool isVisited[18] = {false};
int maxSheep = 0;
bool isStart = true;

void bfs(int sheep, int wolf, int idx) {
    if (sheep <= wolf) {
        return;
    }
    
    if (!isStart && idx == 0) {
        maxSheep = (maxSheep <= sheep) ? sheep : maxSheep;
        return; // ?? 
    }

    if(isStart) !isStart;
    // cout << sheep << " " << wolf << " " << idx << "\n";

    for (auto t : trees[idx]) {
        if (_info[t] != -1) {
            if (_info[t] == 0) {
                _info[t] = -1;
                bfs(sheep+1, wolf, t);
                _info[t] = 0;
            } else if (_info[t] == 1) {
                _info[t] = -1;
                bfs(sheep, wolf+1, t);
                _info[t] = 1;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    _info = info;
    for (auto edge : edges) {
        trees[edge[0]].push_back(edge[1]);
    }
    bfs(1, 0, 0);
    return answer;
}

int main(){
    vector<int> info {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges;
    string s = "[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            if (s[i-1] == ']') continue;
            int a = s[i-1] - '0';
            int b = s[i+1] - '0';
            edges.push_back({a, b});
            i++;
        }
    }
    solution(info, edges);
}