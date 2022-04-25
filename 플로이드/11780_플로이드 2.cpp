// 2022.04.25

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 10000005

int main() {
    int n, m;
    int map[105][105];
    int pre[105][105];

    cin >> n >> m;

    fill(&map[0][0], &map[101][101], MAX);
    memset(pre, -1, sizeof(pre));
    for (int i = 1; i <= n; i++) pre[i][i] = i;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if (map[a][b] >= c) {
            map[a][b] = c;
            pre[a][b] = b;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (j == k || i == j) continue;

                if (map[i][j] >= map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                    pre[i][j] = pre[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == MAX) cout << "0 ";
            else cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == MAX) cout << "0\n";
            else {
                vector<int> vec;
                int st = i;
                // st = pre[i][st]로 해서 틀렸었음 .. 
                while (st != j) {
                    vec.push_back(st);
                    st = pre[st][j];
                }
                vec.push_back(j);
                cout << vec.size() << " ";
                for (auto x : vec) cout << x << " ";
                cout << '\n';
            }
        }
    }
    return 0;
}