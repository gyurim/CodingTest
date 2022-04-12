#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
// 그리디 
// 가장 가격이 높은 보석 -> 가장 작은 가방 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    pair<int, int> jewel[300003];
    multiset<int> bag;

    int m, v;
    for (int i = 0; i < n; i++)
    {   
        cin >> jewel[i].second >> jewel[i].first;
    }
    sort(jewel, jewel+n);
    
    int c;
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        bag.insert(c);
    }
    
    long long totalPrice = 0;
    for (int i = n-1; i >= 0; i--) {
        auto it_bag = bag.lower_bound(jewel[i].second);
        if (it_bag == bag.end()) continue;
        totalPrice += jewel[i].first;
        bag.erase(it_bag);
    }
    
    cout << totalPrice;

    return 0;
}