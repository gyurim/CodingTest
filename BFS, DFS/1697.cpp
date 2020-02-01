#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
bool visit[100001];
int time[100001] = { 0 };

int bfs(int n, int k) {
	q.push(n);
	visit[n] = true;
	int cur = q.front();

	while (cur != k) {
		cur = q.front();
		q.pop();

		if (cur == k) {
			break;
		}
		//범위 체크하는 것이 방문한 것 체크보다 먼저 이루어져야한다. 아니면 런타임에러 뜸
		if ((cur - 1 >= 0) &&!visit[cur - 1]) {
			time[cur - 1] = time[cur] + 1;
			q.push(cur - 1);
			visit[cur - 1] = true;
		}
		if ((cur + 1 <= 100000) &&!visit[cur + 1]) {
			time[cur + 1] = time[cur] + 1;
			q.push(cur + 1);
			visit[cur + 1] = true;
		}
		if ((cur * 2 <= 100000) &&!visit[cur * 2]) {
			time[cur * 2] = time[cur] + 1;
			q.push(cur * 2);
			visit[cur * 2] = true;
		}	
	}

	return time[k];
}

int main() {
	int n, k;
	int min;
	cin >> n >> k;

	min = bfs(n, k);
	cout << min;
	return 0;

}