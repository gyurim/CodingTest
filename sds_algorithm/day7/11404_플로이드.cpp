#include <iostream>
#include <algorithm>
using namespace std;

// 플로이드 워셜 알고리즘
// 3중 for문으로 구현
#define MAX 10000000

int dist[101][101] = {MAX};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int a, b, c;

    fill(dist[0], dist[N+1], MAX); // algorithm include
    // 0 과 -1로 초기화하는 것이 아니라면, memset 대신 fill 사용하기 

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        dist[a][b] = (dist[a][b] > c) ? c : dist[a][b];
    }

    for (int i = 1; i <= N; i++) {
        // i = 경유 노드 
        for (int j = 1; j <= N; j++) {
            if (j == i) continue;

            // j -> i -> (i와 이어진 도착 노드)
            if (dist[j][i] == MAX) continue; // j -> i로 가는 경로 없음

            for (int k = 1; k <= N; k++) {
                if (k == i || k == j) continue;
                if (dist[i][k] == MAX) continue; 

                int ji = dist[j][i];
                int ik = dist[i][k];

                dist[j][k] = (dist[j][k] > ji + ik) ? ji + ik : dist[j][k];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == MAX) cout << 0;
            else cout << dist[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}