#include <string>
#include <vector>
#include <iostream>

#define l 0
#define r 1

using namespace std;

vector<vector<int>> graph(20, vector<int>(20, -1));
vector<int> info;
int ans = 0;

void dfs(int cur, int wolf, int sheep, vector<int> nxt) {
    
    if (info[cur] == 0) sheep++;
    else wolf++;
    // cout << cur << " " << ans << " : " << sheep << " " << wolf << endl;
    ans = max(ans, sheep);
    
    if (wolf >= sheep) return;

    for (int i = 0; i < nxt.size(); i++) {
        vector<int> next = nxt;
        next.erase(next.begin() + i);

        if (graph[nxt[i]][l] != -1) next.push_back(graph[nxt[i]][l]);
        if (graph[nxt[i]][r] != -1) next.push_back(graph[nxt[i]][r]);

        dfs(nxt[i], wolf, sheep, next);
    }
    return;
}

int solution(vector<int> _info, vector<vector<int>> edges) {
    int answer = 0;
    info = _info;

    for (auto e : edges) {
        int parent = e[0];
        int child = e[1];

        if (graph[parent][l] == -1) graph[parent][l] = child;
        else graph[parent][r] = child;
    }
    vector<int> nxt;
    if (graph[0][l] != -1) nxt.push_back(graph[0][l]);
    if (graph[0][r] != -1) nxt.push_back(graph[0][r]);
    dfs(0, 0, 0, nxt);
    cout << ans << endl;
    return ans;
}

int main(){
    vector<int> info {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges;
    string s = "[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            if (s[i-1] == ']') continue;
            int a, b;
            if (s[i-2] == '[') a = s[i-1] - '0';
            else if (s[i-3] == '[') {
                string sa = "";
                sa += s[i-2];
                sa += s[i-1];
                a = atoi(sa.c_str());
            }

            if (s[i+2] == ']') {
                b = s[i+1] - '0';
                i += 2;
            }
            else if (s[i+3] == ']') {
                string sb = "";
                sb += s[i+1];
                sb += s[i+2];
                b = atoi(sb.c_str());
                i += 3;
            }
            edges.push_back({a, b});
        }
    }
    solution(info, edges);
}