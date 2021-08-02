#include <iostream>
#include <vector>

using namespace std;

vector<int> number;
int n, s;
int cnt = 0;
bool isused[21];

void func(int k, int sum) {
    if (k == n) {
        if (sum == s) cnt++;
        return;
    }

    func(k+1, sum);
    func(k+1, sum + number[k]);
}

int main() {
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        number.push_back(num);
    }

    func(0, 0);
    if (s == 0) cnt--; // 합이 0일때, 공집합 제외 
    
    cout << cnt;
    return 0;
}