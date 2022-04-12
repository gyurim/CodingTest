#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000005

long long tree[4 * MAX];
long long arr[MAX];
int n, m, k;

long long init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    // 재귀적으로 두 부분을 나눈 뒤에 그 합을 자기 자신으로 합니다. 
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1); 
}

// start, end: 시작 및 끝 인덱스 
// left, right: 구간 합을 구하고자 하는 범위 
long long sum(int start, int end, int node, int left, int right) {
    // 범위 밖에 있는 경우 
    if (left > end || right < start) return 0;
    // 범위 안에 있는 경우 
    if (left <= start && end <= right) return tree[node];
    // 그렇지 않다면 두 부분으로 나누어 합을 구하기 
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid+1, end, node * 2 + 1, left, right); 
}

// index: 구간 합을 수정하고자 하는 노드
// dif: 수정할 값 
void update(int start, int end, int node, int index, long long dif) {
    // 범위 밖
    if (index < start || index > end) return;
    // 범위 안에 있으면 내려가며 다른 원소도 갱신
    tree[node] += dif;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif); // 왼쪽 자식 
    update(mid+1, end, node * 2 + 1, index, dif); // 오른쪽 자식 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 구간 합 트리의 인덱스를 제외하고는 모두 인덱스 0부터 시작합니다. 
    // 구간 합 트리 생성 
    init(0, n-1, 1);

    for (int i = 0; i < m + k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(0, n-1, 1, b-1, c - arr[b-1]);
            arr[b-1] = c;
        } else if (a == 2) {
            cout << sum(0, n - 1, 1, b-1, c-1) << endl;
        }
    }
    return 0;
}