#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    multiset<long long> s;
    long long x;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (s.size() == 0) cout << "0\n";
            else {
                auto it = prev(s.end());
                cout << *it << '\n';
                s.erase(it);
            }
        } else {
            s.insert(x);
        }
    }
    return 0;
}