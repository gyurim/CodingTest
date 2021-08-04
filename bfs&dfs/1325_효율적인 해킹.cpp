#include <iostream>
#include <vector>
using namespace std;

int relate[10001][10001];
bool visit[10001];

void bfs(int start) {

    visit[start] = true;

}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        relate[a][b] = 1;
        relate[b][a] = 1;
    }

    for (int i = 0; i < m; i++) {

    }
}