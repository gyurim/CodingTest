#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    vector<int> b;
    
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        b.push_back(num);
    }
    
    vector<int> sorted_a = a;
    vector<int> sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end(), greater<int>());
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += sorted_b[i] * sorted_a[i];
    }
    cout << s;
    
    

    // a를 재배열해 s를 최소로 만들기 

    return 0;
}