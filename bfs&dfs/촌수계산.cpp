#include <iostream>
#include <queue>

using namespace std;

// int family[101][101];
vector<vector<int>> family;
bool isVisit[101];

int bfs(int a, int b) {
    queue<int> q;
    isVisit[a] = true;
    q.push(a);
    int cnt = -1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < family[cur].size(); i++) {
            int next = family[cur][i];
            if (!isVisit[next]) {
                q.push(next);
                isVisit[next] = true;
            }
        }
        cnt++;
    }
    return cnt;
}

int main() {
    int n, a, b, m;
    cin >> n;
    cin >> a >> b;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int parent, child;
        cin >> parent >> child;
        
        family[parent].push_back(child);
        family[child].push_back(parent);
    }

    cout << bfs(a, b);
}