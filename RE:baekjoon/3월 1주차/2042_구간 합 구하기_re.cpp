#include <iostream>
using namespace std;

#define MAX 1000005

// vector<long long> arr; // 벡터로 하면 틀림.. 배열로하면 정답 왜 ?? 
long long tree[MAX * 4];
long long arr[MAX];

long long init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int left, int right, int node) {
    if (start > right || end < left) return 0;
    // 이 부분 헷갈림 
    if (left <= start && end <= right) return tree[node]; 
    int mid = (start + end) / 2;
    return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int node, int index, long long diff) {
    if (start > index || end < index) return;
    tree[node] += diff;
    
    if (start == end) return;

    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init(0, n-1, 1);

    for (int i = 0; i < m + k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            // update
            update(0, n-1, 1, b-1, c - arr[b-1]);
            arr[b-1] = c;
        } else if (a == 2) {
            // sum 
            cout << sum(0, n-1, b-1, c-1, 1) << endl;
        }   
    }
    return 0;
}