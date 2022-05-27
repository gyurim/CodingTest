#include <iostream>
#include <queue>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    cin >> n;

    long long ans = 0;
    long long p_sum = 0;
    // 10 20 30 40 50 60
    // (10 + 20) + (30 + 30) + (60 + 40) + (70 + 50) + (120 + 60) // 틀린 예제;
    // 문제 이해 잘못함. 무조건 그 앞에 걸로 안해도 되고 토너먼트 형식으로 하면 됨 ㅜㅜ ..
    // 20 40 50 60
    // queue<int> q;
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙 

    while(n--) {
        cin >> c;
        pq.push(c);
    }
    
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
        ans += (a+b);
    }
    cout << ans;
    return 0;
}