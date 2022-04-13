// 2022.04.13

#include <iostream>
using namespace std;

int n, m;
bool isVisit[10];
int arr[10];

void func(int st, int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = st; i <= n; i++) {
        if (!isVisit[i]) {
            isVisit[i] = true;
            arr[k] = i;
            func(i+1, k+1);
            isVisit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    func(1, 0);
}