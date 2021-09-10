#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**************************************************************************************
 * 카카오 2021 광고 삽입 문제에서 사용했던 Prefix Sum 사용
**************************************************************************************/

int main() {
    int n;
    cin >> n;

    map<long long, int> timeline;
    map<long long, int>::iterator it;

    for (int i = 0; i < n; i++) {
        int st, tt;
        cin >> st >> tt;

        it = timeline.find(st);

        if (it != timeline.end()) {
            it->second++;
        } else {
            timeline.insert(make_pair(st, 1));
        }

        it = timeline.find(tt);

        if (it != timeline.end()) {
            it->second--;
        } else {
            timeline.insert(make_pair(tt, -1));
        }
    }

    int max = 0;

    for (it = timeline.begin(); it != timeline.end(); it++) {
        if (it == timeline.begin()) continue;
        auto prev = it;
        prev--;

        it->second += prev->second;
        max = (max < it->second) ? it->second : max;
    }
    cout << max;
    return 0;
}
