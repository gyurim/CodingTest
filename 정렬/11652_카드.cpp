// #include <iostream>
// #include <algorithm>
// #include <map>

// using namespace std;

// int main() {
//     long long N, num;
//     map<long long, int> m;
//     cin >> N;

//     while(N--) {
//         cin >> num;
//         m[num]++;
//     }

//     int max = 0;
//     long long result;
//     for (auto n:m) {
//         if(n.second > max) {
//             max = n.second;
//             result = n.first;
//         }
//     }
//     cout << result;
//     return 0;
// }

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<long long, int>& a, const pair<long long, int>& b) {
    if (a.second == b.second) 
        return a.first < b.first; // 같으면 first가 더 작은 애를 return 
    else 
        return a.second > b.second;
}

int main() {
    int n;
    cin >> n;

    map<long long, int> m;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        m[num] += 1; // map에서 int형인 경우 초기값은 0이다. 
    }

    vector<pair<long long, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    
    cout << vec[0].first;
    return 0;
}