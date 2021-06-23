#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, v;
vector <int> node[1001];

bool dfsVisit[1001];
bool bfsVisit[1001];

void bfs(){
    queue <int> q;

    bfsVisit[v] = true;
    q.push(v);
    
    while(!q.empty()){
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (int i = 0; i < node[current].size(); i++){
            if (!bfsVisit[node[current][i]]){
                bfsVisit[node[current][i]] = true;
                q.push(node[current][i]);
            }
        }
    }
}

void dfs(int current){
    cout << current << " ";
    dfsVisit[current] = true;

    for (int i = 0; i < node[current].size(); i++){
        int next = node[current][i];

        if (!dfsVisit[next]){
            dfs(next);
        }
    }
}

int main(){
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        node[a].push_back(b);
        node[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        sort(node[i].begin(), node[i].end());
    }

    dfs(v);
    cout << "\n";
    bfs();

    return 0; 
}