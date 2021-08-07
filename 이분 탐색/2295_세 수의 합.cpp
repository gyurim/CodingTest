#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int n;
    ll u[1001];
    bool flag[1001];
    vector<ll> two;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }

    sort(u, u + n);

    for (int i = 0; i < n; i++) 
        for (int j = i; j < n; j++) 
            two.push_back(u[i] + u[j]);

    sort(two.begin(), two.end());

    for (int i = n - 1;  i > 0; i--) {
        for (int j = 0; j < i; j++) {
            ll sum = u[i] - u[j];

            if (binary_search(two.begin(), two.end(), sum))  {
                cout << u[i];
                return 0;
            }
        }
    }

    // O(N^3 log N) 풀이법 -> 시간 초과 남

    // for (int i = 0; i < n; i++) {
    //     if (i < 3) flag[i] = 0;
    //     else flag[i] = 1;
    // }

    // long long sum = 0;

    // do {
    //     long long result = 0;
    //     int indexes = 0;

    //     for (int i = 0; i < n; i++) {
    //         if (flag[i] == 0) {
    //             result += u[i];
    //         }
    //     }
    //     if (binary_search(u, u+n, result))
    //         max(sum, result);
    // } while(next_permutation(flag, flag + n));

    // cout << sum;

    return 0;
}

// 풀이 1) 계속 오류가 났던 이유는 two 배열에 연속된 값들의 합만 넣어줬기 때문. 모든 값들에 대한 합을 넣어줘야한다. 
// 그리고 u를 sort 시킨 다음 binary_search에서 뒤의 u의 맨 뒤 원소부터 차례로 확인하면 binary_search를 통해 처음 찾은 값이 max가 된다. 따라서 연산 수 줄일 수 있음
// -> 풀이 2에 반영 
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int n;
    ll u[1001];
    bool flag[1001];
    vector<ll> two;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            two.push_back(u[i] + u[j]);
        }
    }

    sort(two.begin(), two.end());

    ll result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll sum = u[i] - u[j];

            if (binary_search(two.begin(), two.end(), sum)) {
                result = max(result, u[i]);
            }
        }
    }
    cout << result;
    
    return 0;
}
*/