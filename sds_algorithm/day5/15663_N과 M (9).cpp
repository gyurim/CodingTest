#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> vec;
    vector<vector<int>> seq;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }   

    sort(vec.begin(), vec.end());

    do {
        vector<int> seqs;
        for (int i = 0; i < m; i++)
            seqs.push_back(vec[i]);

        // 이전의 배열과 같은지 
        if (seq.empty()) 
            seq.push_back(seqs);

        if (seq[seq.size()-1] != seqs)
            seq.push_back(seqs);

    } while (next_permutation(vec.begin(), vec.end()));

    for (int i = 0; i < seq.size(); i++) {
        for (int j = 0; j < m; j++)
            cout << seq[i][j] << " ";
        cout << "\n";
    }

    return 0;
}