#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

map<int, int> m;
set<int> u_set;

bool bfs(int node, int maxNum) {
    bool isVisited[maxNum+1];
    queue<int> q;
    q.push(node);
    bool isTree = true;
    map<int, int>::iterator it = m.begin();

    while(!q.empty()) {
        int front = q.front();
        isVisited[front] = true;
        q.pop();

        for(it = m.begin(); it != m.end(); it++) {
            if (front == it->second) {
                if (!isVisited[it->first]) {
                    q.push(it->first);
                    isVisited[it->first] = true;
                }     
            }
        }
    }
    
    for (it = m.begin(); it != m.end(); it++) {
        if (!isVisited[it->first]) {
            isTree = false;
        }
    }
    
    return isTree;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int u, v;
    cin >> u >> v;
    int cnt = 1;
    bool isTree = true;
    int maxNum = 0;

    while(u >= 0 && v >= 0) {
        if (u == 0 && v == 0) {
            vector<int> root;
            
            for (auto it : u_set) {
                if (m.find(it) == m.end()) {
                    root.push_back(it);
                }
            }

            if (root.size() != 1) {
                isTree = false;
            }
            else {
                if (!bfs(root.front(), maxNum)){
                    isTree = false;
                }
            }

            if (isTree || m.size() == 0) 
                cout << "Case " << cnt << " is a tree." << endl;
            else 
                cout << "Case " << cnt << " is not a tree." << endl;
            cnt++;

            // map, set 메모리 초기화 
            m.clear();
            u_set.clear();
            maxNum = 0;
            isTree = true;
            cin >> u >> v;
            continue;
        } 
        
        if (m.find(v) == m.end()) {
            m.insert({v, u});
            u_set.insert(u);
            maxNum = (maxNum < u) ? u : maxNum;
            maxNum = (maxNum < v) ? v : maxNum;
        } else {
            isTree = false;
        }

        cin >> u >> v;
    }
}