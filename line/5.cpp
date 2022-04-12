#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> abilities, int k) {
    long long answer = 0;
    sort(abilities.begin(), abilities.end(), greater<int>());
    vector<pair<int, int>> diffs;
    
    for (int i = 0; i < abilities.size(); i += 2) {
        int diff = abilities[i] - abilities[i+1];
        diffs.push_back({diff, i});
    }
    sort(diffs.begin(), diffs.end(), greater<pair<int, int>>());

    for (int i = 0; i < diffs.size(); i++) {
        int idx = diffs[i].second;
        if (i < k) {
            answer += abilities[idx];
        } else answer += abilities[idx+1];
    }
    return answer;
}
// int main() {
//     vector<int> abilities {10, 9, 8, 3, 1};
//     cout << solution(abilities, 1);
// }