#include <iostream>
#include <algorithm>
using namespace std;

// 이분탐색 코드 
/*
int main(){
    int n, m;
    cin >> n >> m;

    int arr[100001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    int i = 0;
    long answer = 0x3f3f3f3f; // 이거 땜에 틀렸음 진짜 실화냐 min은 제일 큰걸로 ... 

    for (int i = 0; i < n-1; i++) {
        auto idx = lower_bound(arr + i, arr + n, arr[i] + m);
        if (idx == arr + n) break;
       
        long diff = *idx - arr[i];
        if (diff >= m) {
            answer = (answer > diff) ? diff : answer;
        }
    }
    cout << answer;
    
    return 0;
}
*/

// 투 포인터
int main() {
    int n, m;
    cin >> n >> m;

    int arr[100001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int st, en = 0; 
    int answer = 0x7fffffff;

    while(st < n) {
        if (en < n) break;
        int diff = arr[en] - arr[st];
 
        if (diff >= m) {
            st++;
            answer = (answer > diff) ? diff : answer;
        } else if (diff < m) {
            en++;
        }
    }
    cout << answer;
    return 0;
}