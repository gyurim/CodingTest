// 방법 1 

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int main(){
//     int n, m, k;
//     cin >> n >> m;

//     // int lamp[51][51] = {0};
//     string arr[50];

//     // vector<int> zero;
//     int zero[51] = {0};

//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     cin >> k;
    
//     int max = 0;
//     for (int i = 0; i < n; i++) {
//         int count = 0;
//         int zerocnt = 0;
//         for (int j = 0; j < m; j++) {
//             if (arr[i][j] == '0') zerocnt++;
//         }
        
//         if (zerocnt <= k && k % 2 == zerocnt % 2) {
//             for (int j = 0; j < n; j++) {
//                 if (arr[i] == arr[j]) count++;
//             }
//         } 
//         max <= count ? max = count : max = max;
//     }
//     cout << max;

//     return 0;
// }

// 방법 2 (해결 X) 
// 왜 int형은 안됨 ? 비교하는 부분에서 오류 있는거 같음 ;; 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m;

    int lamp[51][51] = {0};
    // vector<int> zero;
    int zero[51] = {0};

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        // int zerocnt = 0;
        for (int j = 0; j < m; j++) {
            lamp[i][m-j-1] = num % 10; 
            // if (num % 10 == 0) zerocnt++;
            num /= 10;
        }
        // zero[i] = zerocnt;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << lamp[i][j] << " ";
        }
        cout << endl;
    }

    cin >> k;
    
    int max = 0;
    for (int i = 0; i < n; i++) {
        // 행에 있는 0의 개수가 K 보다 작거나 같아야함 
        // K가 짝수라면, 0의 개수도 짝수여야함 && 홀수 -> 홀수 
        int count = 0;
        int zerocnt = 0;
        for (int j = 0; j < m; j++) {
            if (lamp[i][j] == 0) zerocnt++;
        }
        
        if (zerocnt <= k && k % 2 == zerocnt % 2) {
            for (int j = 0; j < n; j++) {
                for (int h = 0; h < m; h++) {
                    if (lamp[i][h] != lamp[j][h]) break;
                    if (h == m-1) count++;
                }
            }
        } 
        max <= count ? max = count : max = max;
    }
    cout << max;

    return 0;
}