#include <iostream>
#include <queue>

using namespace std;

#define ppp pair<int, pair<int, int>>
// MST 문제 
// 크루스칼 알고리즘 사용 
// union find를 사용해서 부모가 같은지 확인 
priority_queue<ppp, vector<ppp>, greater<ppp>> pq; // 최소 힙 (오름차순)
int parent[1005];
int n, m;

void Union(int a, int b) {
    if (a > b) parent[a] = b;
    else parent[b] = a; 
}

int FindParent(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = FindParent(parent[a]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    int answer = 0;

    while(!pq.empty()) {
        int nodeA = pq.top().second.first;
        int nodeB = pq.top().second.second;

        int parentA = FindParent(nodeA);
        int parentB = FindParent(nodeB);

        if (parentA == parentB)
            pq.pop();
        else {
            answer += pq.top().first;
            Union(parentA, parentB);
            pq.pop();
        }
    }
    cout << answer;

    return 0;
}