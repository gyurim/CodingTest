#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

pair<int, int> jewel[300001];
multiset<int> bag;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> jewel[i].second >> jewel[i].first;
    }

    sort(jewel, jewel + n);

    int bag_weight;

    for (int i = 0; i < k; i++) {
        cin >> bag_weight;
        bag.insert(bag_weight);
    }

    long long sum = 0;

    for (int i = n-1; i >= 0; i--) {
        auto it = bag.lower_bound(jewel[i].second);
        if (it != bag.end()) {
            sum += jewel[i].first;
            bag.erase(it);
        }
    }

    cout << sum;

    return 0;
}