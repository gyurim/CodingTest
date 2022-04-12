#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

struct Data {
    int node;
    int weight;
    Data() {};
    Data(int node, int weight) : node(node), weight(weight) {};
    bool operator<(const Data d) const {
        return weight > d.weight;
    }
};

vector<Data> v[10];
int dist[10];
bool isVisited[10];
priority_queue<Data> pq;

int N, M;
int a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 초기화 
    for (int i = 0; i <= N; i++) {
        v[i].clear(); 
        dist[i] = INF;
        isVisited[i] = false;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        // 양방향 그래프 
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));
    }
    
    dist[1] = 0; // 시작 값 0으로 
    pq.push(Data(1, 0));

    while(true) {
        if (!pq.empty()) break;
        Data now = pq.top();
        pq.pop();
        if (isVisited[now.node]) continue; // 방문했다면 스킵 
        isVisited[now.node] = true;

        for (int i = 0; i < v[now.node].size(); i++) {
            Data next = v[now.node].at(i);
            if (dist[next.node] > dist[now.node] + next.weight) {
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << "dist " << i << ": " << dist[i] << " ";
    }
    return 0;
}