// 2022.04.23

#include <string>
#include <vector>

using namespace std;

int l[20], r[20];
vector<int> val;
int vis[1<<17]; // 상태 x를 방문했는가?
int ans = 1; // 루트는 항상 양 

void dfs(int state) {
    if (vis[state]) return; 
    vis[state] = true;

    // 늑대 수 세기 
    int wolf = 0, num = 0;
    for (int i = 0; i < val.size(); i++) {
        if (state & (1<<i)) {
            num++;
            wolf += val[i];
        }
    }

    // 늑대가 절반 초과하면 안됨 
    if (wolf * 2 >= num) return;
    ans = max(ans, num - wolf);

    for (int i = 0; i < val.size(); i++) {
        if (!(state & (1 << i))) continue;
        if (l[i] != -1) 
            dfs(state | (1 << l[i]));
        
        if (r[i] != -1)
            dfs(state | (1 << r[i]));
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    val = info;

    fill(l, l+20, -1);
    fill(r, r+20, -1);

    for(auto e : edges) {
        int p = e[0];
        int c = e[1];

        if (l[p] == -1) l[p] = c;
        else r[p] = c;
    }
    dfs(1); // 0번 노드만 포함 (2진법)
    return ans;
}