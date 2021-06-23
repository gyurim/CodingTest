/***********************************************
			BOJ 2178
***********************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <char>v[101];
bool visit[101][101];
queue <int> qx;
queue <int> qy;

int bfs(int x, int y, int n, int m) {
	int cur_distance[101][101] = { 1 };
	qx.push(x);
	qy.push(y);

	visit[x][y] = true;
	int cur_x = qx.front();
	int cur_y = qy.front();

	while (!qx.empty() || !qy.empty() ) {
		cur_x = qx.front();
		cur_y = qy.front();

		if ((cur_y < m-1) && (v[cur_x][cur_y + 1] == '1') && !visit[cur_x][cur_y + 1]) {
			qx.push(cur_x);
			qy.push(cur_y + 1);
			visit[cur_x][cur_y + 1] = true;
			cur_distance[cur_x][cur_y + 1] = cur_distance[cur_x][cur_y] + 1;
		}
		if ((cur_y - 1 >= 0) && (v[cur_x][cur_y - 1] == '1') && !visit[cur_x][cur_y - 1]) {
			qx.push(cur_x);
			qy.push(cur_y - 1);
			visit[cur_x][cur_y - 1] = true;
			cur_distance[cur_x][cur_y - 1] = cur_distance[cur_x][cur_y] + 1;
		}
		if ((cur_x - 1 >= 0) && (v[cur_x - 1][cur_y] == '1') && !visit[cur_x - 1][cur_y]) {
			qx.push(cur_x - 1);
			qy.push(cur_y);
			visit[cur_x - 1][cur_y] = true;
			cur_distance[cur_x -1][cur_y] = cur_distance[cur_x][cur_y] + 1;
		}
		if ((cur_x < n-1) && v[cur_x + 1][cur_y] == '1' && !visit[cur_x + 1][cur_y]) {
			qx.push(cur_x + 1);
			qy.push(cur_y);
			visit[cur_x + 1][cur_y] = true;
			cur_distance[cur_x+1][cur_y] = cur_distance[cur_x][cur_y] + 1;
		}

		qx.pop();
		qy.pop();

	}

	return cur_distance[n-1][m-1];
}

int main() {
	int n, m;
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		char idx[101];
		cin >> idx;

		for (int j = 0; j < m; j++) {
			v[i].push_back(idx[j]);
		}
	}

	int distance = bfs(0, 0, n, m);
	cout << distance;
	
	return 0;
}