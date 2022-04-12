#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxheap, minheap;

    int N;
    cin >> N;

    for (int i = 0, num; i < N; i++) {
        cin >> num;
        if (maxheap.size() > minheap.size()) 
            minheap.push(-num); // 음수를 붙여 넣으면 음수 중 가장 큰 값이 나오게 되고, 그게 양수의 경우 가장 min 값이기 때문 
        else maxheap.push(num); // 처음은 maxheap부터 채워넣음  

        // pq에 값이 들어있는 경우  
        if (maxheap.size() > 0 && minheap.size() > 0) {
            // maxheap에 더 큰 경우, minheap과 교환
            if (maxheap.top() > -minheap.top()) {
                int maxtop = maxheap.top();
                int mintop = -minheap.top();

                maxheap.pop();
                minheap.pop();
                maxheap.push(mintop);
                minheap.push(-maxtop);
            }
        } 
        cout << maxheap.top(); // 답은 항상 maxheap의 top에 있다. 
    }
    return 0;
} 