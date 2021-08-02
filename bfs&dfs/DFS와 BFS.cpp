
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/********************************************************
 * 방법 1
*********************************************************/
int n, m;
// vector<vector<int>> adjacent;
int adjacent[1001][1001];
bool visit[1001];

// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
 
void bfs(int v) {
    queue <int> q;
    q.push(v);
    visit[v] = true;
    cout << v << " ";

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 1; i <= n; i++){
            if (adjacent[node][i] == 1 && !visit[i]) {
                q.push(i);
                visit[i] = true;
                cout << i << " ";
            }
        }
    }
}

void dfs(int v) {
    visit[v] = true;
    cout << v << " ";

    for (int i = 1; i <= n; i++) {
        if (adjacent[v][i] == 1 && !visit[i]) {
            dfs(i);
        }
    }
}

int main() {
    int v; 
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++ ){
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;

        adjacent[nodeA][nodeB] = 1;
        adjacent[nodeB][nodeA] = 1;
    }
    dfs(v);

    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }

    cout << "\n";
    bfs(v);
}

/********************************************************
 * 방법 2
*********************************************************/
// int n, m, v;
// vector <int> node[1001];

// bool dfsVisit[1001];
// bool bfsVisit[1001];

// void bfs(){
//     queue <int> q;

//     bfsVisit[v] = true;
//     q.push(v);
    
//     while(!q.empty()){
//         int current = q.front();
//         cout << current << " ";
//         q.pop();
//         for (int i = 0; i < node[current].size(); i++){
//             if (!bfsVisit[node[current][i]]){
//                 bfsVisit[node[current][i]] = true;
//                 q.push(node[current][i]);
//             }
//         }
//     }
// }

// void dfs(int current){
//     cout << current << " ";
//     dfsVisit[current] = true;

//     for (int i = 0; i < node[current].size(); i++){
//         int next = node[current][i];

//         if (!dfsVisit[next]){
//             dfs(next);
//         }
//     }
// }

// int main(){
//     cin >> n >> m >> v;

//     for (int i = 0; i < m; i++){
//         int a, b;
//         cin >> a >> b;

//         node[a].push_back(b);
//         node[b].push_back(a);
//     }

//     for (int i = 1; i <= n; i++){
//         sort(node[i].begin(), node[i].end());
//     }

//     dfs(v);
//     cout << "\n";
//     bfs();

//     return 0; 
// }