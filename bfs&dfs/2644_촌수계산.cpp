#include <iostream>
#include <vector>
using namespace std;

vector<int> re[101];
bool isvisit[101];
int n;

int dfs(int start, int target, int cnt) {
    isvisit[start] = true;
    if (start == target) {
        return cnt;
    }
    for (int i = 0; i <= re[start].size(); i++) {
        int next = re[start][i];
        if (!isvisit[next]) {
            dfs(next, target, cnt+1);
        }
    }
    return -1;
}

int main() {
    int a, b, m;
    cin >> n;
    cin >> a >> b;
    cin >> m;

    while(m--) {
        int x, y;
        cin >> x >> y;
        re[x].push_back(y);
        re[y].push_back(x);
    }
    cout << dfs(a, b, 0);
    return 0;
}