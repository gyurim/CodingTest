#include <iostream>
#include <vector>

using namespace std;

int main() {
    int answer = 0;
    long long n, m;
    cin >> n >> m;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int num; 
        cin >> num;
        vec.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        long long sum = vec[i];
        
        if (sum == m) {
            answer++;
            continue;
        }
        if (i == n-1) break;
        
        for (int j = i+1; j < n; j++) {
            sum += vec[j];
            if (sum == m) {
                answer++;
                break;
            }
        }
        
    }

    cout << answer;
    return 0;
}