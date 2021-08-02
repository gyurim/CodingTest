#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> freq;

    while(n--){
        int num;
        cin >> num;
        freq.push_back(num);
    }

    sort(freq.begin(), freq.end());

    for (int it : freq) {
        cout << it << '\n';
    }

    return 0;
}

// 시간초과 
// #include <iostream> 
// #include <map>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int n;
//     cin >> n;

//     map<int, int> freq;
//     map<int, int>::iterator it;

//     while(n--){
//         int num;
//         cin >> num;
//         if ((it = freq.find(num)) == freq.end()) 
//             freq.insert(make_pair(num, 1));
//         else 
//             it -> second++;  
//     }

//     for (auto it : freq) {
//         for (int i = 0; i < it.second; i++)
//             cout << it.first << '\n';
//     }
    
//     return 0;
// }