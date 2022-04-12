#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> odd;
        vector<int> even;
        int sum = 0;

        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num % 2 == 0) even.push_back(num);
            else odd.push_back(num);
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        int lastOdd = -1;
        int lastEven = -1;

        // 연아가 받을 수 있는 최대 점수
        if (odd.size() % 2 == 0) {
            for (auto it = odd.begin() + odd.size()/2; it != odd.end(); it++) {
                sum += *it;
            }
        } else {
            auto it = odd.begin() + odd.size()/2;
            lastOdd = *it;
            for (it = ++it; it != odd.end(); it++) {
                sum += *it;
            }
        }

        if (even.size() % 2 == 0) {
            for (auto it = even.begin() + even.size()/2; it != even.end(); it++) {
                sum += *it;
            }
        } else {
            auto it = even.begin() + even.size()/2;
            lastEven = *it;
            for (it = ++it; it != even.end(); it++) {
                sum += *it;
            }
        }
        
        // 나머지 계산 
        if (lastOdd != -1 && lastEven != -1) {
            sum += min(lastOdd, lastEven);
        }
        cout << "#" << i+1 << " " << sum << "\n";
    }
    
    return 0;
}