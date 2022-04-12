#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>

using namespace std;

vector<int> vec;
set<int> comb;
bool isVisit[11];
int n, k;
string s = "";
vector<int> card;

void backtracking(int depth) {

    if (depth == k) {
        string s = "";
        for (auto c : card) s += to_string(c);
        comb.insert(stoi(s));
        return;
    } 

    for (int i = 0; i < n; i++) {
        if (isVisit[i]) continue;
        
        isVisit[i] = true;
        card.push_back(vec[i]);
        backtracking(depth+1);
        card.pop_back();
        isVisit[i] = false;
    }
}

int main() {   
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    backtracking(0);

    cout << comb.size();
    return 0;
}