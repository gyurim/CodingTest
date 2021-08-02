#include <iostream>
using namespace std;

int n, m;
bool isused[10];
int arr[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    func(0);
    return 0;
}

// #include <iostream>
// using namespace std;

// int n, m;
// int arr[10];
// bool isused[10];

// void func(int k) { // arr[k]를 정하는 함수 
//     if (k == m) {
//         for (int i = 0; i < m; i++) 
//             cout << arr[i] << ' ';
//         cout << '\n';
//         return;
//     }

//     for (int i = 1; i <= n; i++) {
//         if (!isused[i]) {
//             arr[k] = i;
//             isused[i] = 1;
//             func(k+1);
//             isused[i] = 0;
//         }
//     }
// }

// int main(){
//     cin >> n >> m;
//     func(0);
// }