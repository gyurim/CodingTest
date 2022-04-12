#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        multiset<int> ms;
        bool isEmpty = false;

        for (int i = 0; i < k; i++) {
            char cmd;
            int num;
            cin >> cmd >> num;
        
            if (cmd == 'I') {
                ms.insert(num);
            } else if (cmd == 'D') {
                if (num == 1) {
                    if (ms.size() == 0) continue;
                    else ms.erase(prev(ms.end()));  

                } else if (num == -1) {
                    if (ms.size() == 0) continue;
                    else ms.erase(ms.begin());
                }
            }
        }

        if (ms.size() == 0) cout << "EMPTY\n";
        else {
            auto it1 = prev(ms.end());
            auto it2 = ms.begin();
            cout << *it1 << ' ' << *it2 << '\n';
        }
    }
    return 0;
}