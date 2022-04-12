#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> tree;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (auto i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.push_back(x);
    }

    sort(tree.begin(), tree.end());

    int start = 0;
    int end = tree[n-1];
    int result = 0;

    while (start <= end) {
        long long total = 0;
        int mid = (start + end) / 2;

        for (auto i = 0; i < n; i++) {
            if (tree[i] > mid)
                total += (tree[i] - mid);
        }

        if (total < m) {
            end = mid - 1;
        } else {
            start = mid + 1;
            result = mid;
        }
    }
    cout << result;
    return 0; 
}