#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> vec[10001];
bool visit[10001];
int n, m;
int cnt[10001];

int bfs(int s) {
    int cnt = 1;
    queue<int> q;
    visit[s] = true;
    q.push(s);

    while(!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; i < vec[f].size(); i++) {
            int next = vec[f][i];
            if (!visit[next]) {
                q.push(next);
                visit[next] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[b].push_back(a);
    }
    map<int, int> m;
    int max = -1;

    for (int i = 1; i <= n; i++) {
        memset(visit, false, sizeof(visit));
        cnt[i] = bfs(i);
        m.insert(make_pair(i, cnt[i]));
        max = (max < cnt[i]) ? cnt[i] : max;
    }

    vector<int> vecCnt;
    
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == max) {
            vecCnt.push_back(it->first);
        }
    }
    sort(vecCnt.begin(), vecCnt.end());
    for(int i = 0; i < vecCnt.size(); i++) cout << vecCnt[i] << " ";
    
    return 0;
}