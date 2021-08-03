#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue<int> q;
    int cnt = 1;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) 
        q.push(i);
    
    cout << "<";

    while(!q.empty()) {
        if (cnt == k) {
            if (q.size() == 1) 
                cout << q.front();
            else 
                cout << q.front() << ", ";
            q.pop();
            cnt = 1;
        } else {
            q.push(q.front());
            q.pop();
            cnt++;
        }
    }
    cout << ">";

    return 0;
}