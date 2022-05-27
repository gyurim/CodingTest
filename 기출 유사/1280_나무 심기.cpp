#include <iostream>
#include <cstring>

using namespace std;
// 못 하겠음 ! 

#define max 200005
#define mod 1000000007
// 팬윅트리 (= 바이너리 인덱스 트리) 사용 
long long tree[4 * max]; // 바이너리 인덱스 트리 
long long arr[max]; // 나무의 인덱스가 저장되어 있음 
int n;

long long init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
    // 범위 밖에 있는 경우 
    if (left > end || right < start) return 0;
    // 범위 안에 있는 경우
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init(0, n-1, 1); 
    long long ans = 1;

    for (int i = 1; i < n; i++) {
        long long cost = 0;
        for (int j = i - 1; j < i; j++) {
            cost += sum(0, n-1, 1, j, i);
            cost %= mod;
        }
        ans *= cost;
        ans %= mod;
    }

    cout << ans;
    return 0;
}