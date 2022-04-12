#include <iostream>
#include <queue>

using namespace std;

struct Data {
    int a, b, c;
    Data(){}; // 기본 생성자 
    Data(int a, int b, int c)
        : a(a), b(b), c(c) {};

    bool operator<(const Data d) const {
        return c > d.c;
    }
};

int n, m;
priority_queue<Data> pq;
int parent[1001];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
    parent[find(a)] = find(b);
}

int main(){
    // 필수 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        pq.push(Data(a, b, c));
    }

    // parent 초기화 
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    // 크루스칼 알고리즘 종료 조건: N - 1개의 간선이 연결된 경우 
    int minPaid = 0;
    int linkedCnt = 0;

    while(true) {
        if (linkedCnt == n-1) break;
        Data topData = pq.top();
        pq.pop(); 

        if (find(topData.a) != find(topData.b)) {
            uni(topData.a, topData.b);
            linkedCnt++;
            minPaid += topData.c;
        }
    }
    cout << minPaid;
    return 0;
}