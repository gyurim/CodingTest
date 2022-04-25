// 2022.04.25

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define MAX 10000001 // 100,000 * 100 최대 // int overflow 발생 X
#define MAX_N 105

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int map[MAX_N][MAX_N];
    
    for(int i = 0; i <= n; i++)
        fill(map[i], map[i] + n + 1, MAX);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        map[a][b] = min(map[a][b], c);        
    }

    for (int i = 1; i <= n; i++) {
        for (int  st = 1; st <= n; st++) {
            if (i == st) continue;
            for (int en = 1; en <= n; en++) {
                if (i == en || st == en) continue;
                map[st][en] = min(map[st][en], map[st][i] + map[i][en]); 
                // 대입보다 연산이 빠름 
                // if (map[st][en] > map[st][i] + map[i][en]) map[st][en] = map[st][i] + map[i][en]이 더 빠름 
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
    return 0;
}