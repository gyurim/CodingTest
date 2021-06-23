/***********************************************
			BOJ 10026
***********************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[101][101];
bool rgmed_visit[101][101];

vector <char> v[101];
vector <char> rgmed_v[101];

int n;
int mx[] = { 0,0,1,-1 };
int my[] = { 1, -1, 0,0 };

struct node {
	int x, y;
	node() {}
	node(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

void bfs(int cur_x, int cur_y, char cur_color) {
	queue <node> q;

	q.push({ cur_x, cur_y});
	visit[cur_x][cur_y] = true;

	while (!q.empty()) {
		node nd = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = nd.x + mx[i];
			int y = nd.y + my[i];

			if (y >= 0 && x >= 0 && y <= n-1 && x <= n-1 && v[x][y] == cur_color && !visit[x][y]) {		
				visit[x][y] = true;
				q.push({ x, y });
			}			
		}
	}
}

void rgmed_bfs(int cur_x, int cur_y, char cur_color) {
	queue <node> rgmed_q;

	rgmed_q.push({ cur_x, cur_y });
	rgmed_visit[cur_x][cur_y] = true;

	while (!rgmed_q.empty()) {
		node nd = rgmed_q.front();
		rgmed_q.pop();

		for (int i = 0; i < 4; i++) {
			int x = nd.x + mx[i];
			int y = nd.y + my[i];

			if (y >= 0 && x >= 0 && y <= n - 1 && x <= n - 1 && rgmed_v[x][y] == cur_color && !rgmed_visit[x][y]) {
				rgmed_visit[x][y] = true;
				rgmed_q.push({ x, y });
			}
		}
	}
}

int main() {
	int count = 0;
	int rgmed_count = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {

		char rgb[101];
		cin >> rgb;
		for (int j = 0; j < n; j++) {
			v[i].push_back(rgb[j]);

			if (rgb[j] == 'G' || rgb[j] == 'R') {
				rgmed_v[i].push_back('K');
			}
			else {
				rgmed_v[i].push_back('B');
			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				bfs(i, j, v[i][j]);
				count++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!rgmed_visit[i][j]) {
				rgmed_bfs(i, j, rgmed_v[i][j]);
				rgmed_count++;
			}
		}
	}

	cout << count<<" "<< rgmed_count;

	return 0;
}