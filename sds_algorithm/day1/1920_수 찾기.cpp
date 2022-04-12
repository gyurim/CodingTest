#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a_vec;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        a_vec.push_back(a);
    }
    sort(a_vec.begin(), a_vec.end());
    
    int m; 
    cin >> m;
    int b;

    for (int i = 0; i < m; i++) {
        cin >> b;
        if (binary_search(a_vec.begin(), a_vec.end(), b)) {
            cout << "1\n";
        } else 
            cout << "0\n";
    }  
    return 0;
}