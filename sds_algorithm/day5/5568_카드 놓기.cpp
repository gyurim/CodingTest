#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cards;
    int card;
    for (int i = 0; i < n; i++) {
        cin >> card;
        cards.push_back(card);
    }
    // vector<bool> flag;
    // for (int i = 0; i < n; i++) {
    //     if (i < k) flag.push_back(false);
    //     else flag.push_back(true);
    // }

    set<int> s;
    sort(cards.begin(), cards.end());

    do {
        string str = "";
        for (int i = 0; i < k; i++) {
            str += to_string(cards[i]);
        }
        s.insert(stoi(str));
    } while (next_permutation(cards.begin(), cards.end()));

    cout << s.size();
    return 0;
}