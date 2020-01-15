/**********************************************************************************************
					BOJ 11725
**********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector <int>node[100001];
bool visit[100001] = { false };
int parent[100001];

void search(int r, int n) { //DFS ±¸Çö(Àç±Í)
	
	for (int i = 0; i < node[r].size(); i++) {
		int next = node[r][i];
		if (!visit[next]) {
			visit[r] = true;
			parent[next] = r;
			search(next, n);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;

		node[a].push_back(b);
		node[b].push_back(a);
	}

	search(1, n);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}