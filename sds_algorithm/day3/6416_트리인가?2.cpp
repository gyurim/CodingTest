#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 틀림 ㅋ 100에서 

int a, b;
vector<pair<int, int>> edges;
set<int> node;
int cnt = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        if (a == 0 && b == 0) {
            if (edges.size() + 1 == node.size() || edges.size() == 0) 
                cout << "Case " << cnt << " is a tree." << endl;
            else 
                cout << "Case " << cnt << " is not a tree." << endl; 

            cnt++;
            node.clear();
            edges.clear();
        } else {
            node.insert(a);
            node.insert(b);
            edges.push_back({a, b});
        }
    }
    return 0;
}