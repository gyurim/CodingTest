// 2022.04.13

#include <iostream>
using namespace std;

int n, m;
bool visit[10];
int arr[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            arr[k] = i;
            visit[i] = true;
            func(k+1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    func(0);
    return 0;
}