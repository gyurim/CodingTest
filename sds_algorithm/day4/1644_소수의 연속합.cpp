#include <iostream>
#include <vector>

#define MAX 4000001

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    bool primes[MAX];
    vector<int> prime;

    fill_n(primes, n+1, true);
    primes[1] = false;
    
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            for (int j = 2; j * i <= n; j++) {
                if (!primes[j * i]) continue;
                primes[j*i] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            prime.push_back(i);
        }
    }

    int cnt = 0;
    int ptr1 = 0;
    int ptr2 = 0;
    int sum = 0;

    while (true) {
        // 순서 중요 
        if (sum >= n) {
            sum -= prime[ptr1++];
        } else if (ptr2 == prime.size()) 
            break;
        else {
            sum += prime[ptr2++];
        }

        if (sum == n) cnt++;
    }
    
    cout << cnt;

    return 0;
}

// ----------------------------시간 초과 엔딩----------------------------
// Prefix Sum은 시간 초과 나고;; 투포인터는 시간 초과 안나고 ㅠ 
// Prefix Sum은 이중 for 문이긴 했어 ;; ㅜ 
// --------------------------------------------------------------------
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int n;
//     cin >> n;

//     bool primes[MAX];
//     vector<long long> prime;

//     fill_n(primes, n+1, true);
//     primes[1] = false;
    
//     for (long long i = 2; i <= n; i++) {
//         if (primes[i]) {
//             for (long long j = 2; j * i <= n; j++) {
//                 if (!primes[j * i]) continue;
//                 primes[j*i] = false;
//             }
//         }
//     }

//     prime.push_back(0);

//     for (long long i = 2; i <= n; i++) {
//         if (primes[i]) {
//             if (prime.size() == 1) prime.push_back(i);
//             else prime.push_back(prime[prime.size()-1] + i);
//         }
//     }
//     int cnt = 0;
//     for (long long i = 1; i < prime.size(); i++) {
//         for (long long j = 0; j < i; j++) {
//             if (prime[i]-prime[j] == n) cnt++;
//         }
//     }
//     cout << cnt;

//     return 0;
// }
// --------------------------------------------------------------------

// ----------------------------메모리 초과 엔딩----------------------------
// long long tree[MAX * 4];
// long long arr[MAX];

// long long init(int start, int end, int node) {
//     if (start == end) return tree[node] = arr[start];
//     int mid = (start + end) / 2;
//     return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
// }

// // start, right, end, left 순서 모두 다 외워야됨.. 
// // start > right || left < end 했는데 답 안나와서 삽질함 ㅠㅠ 
// long long sum(int start, int end, int left, int right, int node) {
//     if (start > right || end < left) return 0;
//     if (left <= start && end <= right) return tree[node];
//     int mid = (start + end) / 2;
//     return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
// }

// int main() {
//     int n;
//     cin >> n;
//     bool primes[MAX];
    
//     // 연속된 소수의 합으로 나타낼 수 있는 경우의 수 
//     fill_n(primes, n+1, true);
//     primes[1] = false;
    
//     for (int i = 2; i <= n; i++) {
//         if (primes[i]) {
//             for (int j = 2; j * i <= n; j++) {
//                 if (!primes[j * i]) continue;
//                 primes[j*i] = false;
//             }
//         }
//     }

//     int idx = 0;
//     for (int i = 2; i <= n; i++) {
//         if (primes[i]) {
//             arr[idx] = i;
//             idx++;
            
//         }
//     }

//     init(0, idx-1, 1);
    
//     int cnt = 0;
//     for (int i = 0; i < idx; i++) {
//         for (int j = i; j < idx; j++) {
//             if (sum(0, idx-1, i, j, 1) == n) cnt++;
//         }
//     }
//     cout << cnt;

//     return 0;
// }
// --------------------------------------------------------------------