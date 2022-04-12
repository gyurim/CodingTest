#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int cnt = 0;
        int n, m;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int star;
            cin >> star; 
            q.push({i, star});
            pq.push(star);
        }

        while(!q.empty()) {
            int f = q.front().first;
            int s = q.front().second;

            q.pop();

            if (pq.top() == s) { // 현재 s 중요도가 가장 큰 중요도라면
                pq.pop();
                cnt++;

                if (f == m) {
                    cout << cnt << endl;
                    break;
                }
            } else {
                q.push({f, s});
            }
        }
    }
    return 0;
}