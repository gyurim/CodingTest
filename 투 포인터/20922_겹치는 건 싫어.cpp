#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[200001];
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        auto it = m.find(arr[i]);
        if (it == m.end()) {
            m.insert(make_pair(arr[i], 0));
        }
    }
    
    int max = 0;

    int en = 0;
    auto s_it = m.find(arr[0]);
    s_it->second++;
    
    for (int st = 0; st < n; st++) {
        s_it = m.find(arr[st]);
        
        while (en < n) {
            en++;
            auto e_it = m.find(arr[en]);
            e_it->second++;

            if (e_it->second > k) {
                en--;
                e_it->second--;
                break;
            }
            if (en == n-1) break;
        }
        if (s_it->second > 0) s_it->second--;

        int length = en - st + 1;
        max = (max < length) ? length : max;
        
        if (en == n-1) break;
    }
    cout << max;
    return 0;
}