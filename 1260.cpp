/***********************************************
			BOJ 1260
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> node[1001];
bool d_visit[1001];
bool b_visit[1001];
queue <int> q;
vector <int> dfs_result;
vector <int> bfs_result;
 
void dfs(int v, int m) {
	int cur;

	for (int i = 0; i < node[v].size(); i++) {
		cur = node[v][i];

		if (!d_visit[cur]) {
			dfs_result.push_back(cur);
			d_visit[cur] = true;
			dfs(cur, m);
		}
	}
}

void bfs(int v, int m) {
	int cur;
	q.push(v);
	b_visit[v] = true;
	bfs_result.push_back(v);

	while (!q.empty()) {
		cur = q.front();

		for (int j = 0; j < node[cur].size(); j++) {
			int curNode = node[cur][j];

			if (!b_visit[curNode]) {
				b_visit[curNode] = true;
				bfs_result.push_back(curNode);
				q.push(curNode);
			}
		}
		q.pop();
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		node[a].push_back(b);
		node[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(node[i].begin(), node[i].end());
}

	//dfs
	d_visit[v] = true;
	dfs_result.push_back(v);
	dfs(v, m);

	//bfs
	bfs(v, m);

	//dfs print 
	for (int i = 0; i < dfs_result.size(); i++) {
		cout << dfs_result[i]<<" ";
	}
	cout << "\n";
	//bfs print
	for (int i = 0; i < bfs_result.size(); i++) {
		cout << bfs_result[i] << " ";
	}
	return 0;
}