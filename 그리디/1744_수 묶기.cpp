#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num;
    priority_queue<int, vector<int>, greater<int>> negative_pq; // 최소 pq
    priority_queue<int> positive_pq; // 최대 pq 
    int zero_cnt = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> num;

        if (num > 0) positive_pq.push(num);
        else if (num < 0) negative_pq.push(num);
        else zero_cnt++; // num == 0 
    }

    while (positive_pq.size() > 1) {
        int a = positive_pq.top( );
        positive_pq.pop();
        int b = positive_pq.top();
        positive_pq.pop();
        
        // a or b == 1 인 경우, a*b < a+b 
        ans = ans + max(a+b, a*b); 
    }

    while (negative_pq.size() > 1) {
        int a = negative_pq.top();
        negative_pq.pop();
        int b = negative_pq.top();
        negative_pq.pop();
        ans += (a*b);
    }

    if (negative_pq.size() == 1) {
        if (zero_cnt == 0) ans += negative_pq.top();
        // zero_cnt > 0 이면, top * 0 = 0  
    }
    
    if (positive_pq.size() == 1) ans += positive_pq.top();
    
    cout << ans;

    return 0;
}