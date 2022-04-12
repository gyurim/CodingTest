#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define INF 987654321 // 범위 안 넘어가는 거 중요 
using namespace std;

bool isVisit[1001] = {false};
int cost[1001] = {INF};
vector<pair<int, int>> info[1001]; // 2차원 벡터 
int result[1001];

void Dijkstra(int start_node) {
    priority_queue<pair<int, int>> pq;
    cost[start_node] = 0;
    pq.push({0, start_node}); // 가중치 기준으로 정렬 
    
    while(!pq.empty()) {
        int cur_cost = -pq.top().first; // pq는 기본적으로 최대힙 따라서 - 붙여줌으로써 최소힙으로 사용 
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < info[cur].size(); i++) {
            int next = info[cur][i].first;
            int next_cost = info[cur][i].second;

            if (cost[next] > cur_cost + next_cost) {
                cost[next] = cur_cost + next_cost;
                pq.push(make_pair(-cost[next], next));
            }
        }
    }
}

// 다익스트라 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m >> x;

    int a, b, t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        info[a].push_back({b, t});
    }

    for (int i = 1; i <= n; i++) {
        // 초기화 
        for (int j = 1; j <= n; j++)
            cost[j] = INF;

        Dijkstra(i);
        result[i] = cost[x];
    }
    // 다시 되돌아가는 것까지 
    for (int i = 1; i <= n; i++) 
        cost[i] = INF;
    Dijkstra(x);
    for (int i = 1; i <= n; i++) 
        result[i] += cost[i];

    sort(result+1, result+n+1);
    cout << result[n];

    return 0;
}