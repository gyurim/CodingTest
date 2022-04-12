#include <iostream>
#include <string>
#include <stack>
#include <set>

#define MAX 32005

using namespace std;

int parent[MAX];

// 메모리 초과 왜 남 ??? 
// set 때문인가 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    set<int> isLeaf;

    for (int i = 1; i <= n; i++){
        parent[i] = i;
        isLeaf.insert(i);
    }
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        if (isLeaf.find(a) != isLeaf.end())
            isLeaf.erase(a);

        if (b == parent[b]) { 
            parent[b] = a;
        } else {
            if (a > parent[b]) {
                int parentB = parent[b];
                parent[b] = a;
                parent[a] = parentB;
            }
            else {
                parent[parent[b]] = a;
            }
        }
    }

    stack<int> st;

    for (auto leaf : isLeaf) {
        while(parent[leaf] != leaf) {
            st.push(leaf);
            leaf = parent[leaf];
        }
        st.push(leaf);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}