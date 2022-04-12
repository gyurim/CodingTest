#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string cards[100];
int n;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> isflag;
        int flg_i = 0;
        int flg_cnt = 0;
        int maxCnt = 0;
        for (int j = 0; j < n; j++) {
            cin >> cards[j];

            // here
            if (flg_cnt % 3 == 0) {
                flg_i++;
            }
            isflag.push_back(flg_i);
            flg_cnt++;
        }
        
        sort(isflag.begin(), isflag.end());

        // vector<vector<string>> set(3);
        vector<vector<string>> set(10, vector<string>());
        do {
            int cnt = 0;
            for (int j = 1; j <= n / 3; j++) {
                // cout << "[" << j << "]" << endl;
                vector<string> mset;
                for (int k = 0; k < n; k++) {
                    if (isflag[k] == j) {
                        mset.push_back(cards[k]);
                    }
                }
                
                // for (int l = 0; l < mset.size(); l++) cout << mset[l] << " ";
                // cout << endl;
                // 조건이 맞는지 확인해주기 
                int options[4] = {3, 3, 3, 3};
                for (int k = 0; k <= 3; k++) {
                    string setS = mset[0];
                    string setSS = mset[2];

                    if (setS[k] != setSS[k]) {
                        options[k]--;
                    }

                    for (int h = 1; h < 3; h++) {
                        setS = mset[h];
                        setSS = mset[h-1];
                        if (setS[k] != setSS[k]) 
                            options[k]--;
                    }
                }

                int notSameCnt = 0;
                for (int k = 0; k < 4; k++) {
                    if (options[k] == 1 || options[k] == 2) notSameCnt++;
                }
                if (notSameCnt == 0) {
                    set.push_back(mset);
                    cnt++;
                }
            }
            maxCnt = max(cnt, maxCnt);
  
        } while(next_permutation(isflag.begin(), isflag.end()));
        cout << "#" << i + 1 << " " << maxCnt << "\n";
    }
    return 0;
}