#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> seqs;
    vector<int> nums;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    do {
        vector<int> seq;
        vector<int> sorted;
        for (int i = 0; i < m; i++) {
            seq.push_back(nums[i]);
        }

        sorted = seq;
        sort(sorted.begin(), sorted.end());
        if (seqs.empty()) seqs.push_back(seq);
        else if (sorted == seq && seq != seqs[seqs.size()-1])
            seqs.push_back(seq);

    } while (next_permutation(nums.begin(), nums.end()));

    for (int i = 0; i < seqs.size(); i++) {
        for (int j = 0; j < m; j++) {
            cout << seqs[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}