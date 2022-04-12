#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool isvisited[1005] = { false };
vector<vector<int>> graphs(1005);

void bfs(int cur){
    queue<int> q;
    q.push(cur);
    isvisited[cur] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graphs[x].size(); i++) {
            int next_x = graphs[x][i];
            if (!isvisited[next_x]) {
                q.push(next_x);
                isvisited[next_x] = true;
            } 
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (!isvisited[i]){
            bfs(i);
            // cout << i << endl;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}