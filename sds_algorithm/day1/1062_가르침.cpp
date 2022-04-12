#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> ss;
vector<char> alphabet;
vector<int> flags;
int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        s = s.substr(4, s.size() - 8);
        ss.push_back(s);
        
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'a' || s[j] == 'n' || s[j] == 't' || s[j] == 'i' || s[j] == 'c') continue;
            alphabet.push_back(s[j]);
        }
    }

    if (k < 5) {
        cout << "0";
    } else {
        sort(alphabet.begin(), alphabet.end());
        alphabet.erase(unique(alphabet.begin(), alphabet.end()), alphabet.end());

        // set 조합  
        for (int i = 0; i < alphabet.size(); i++) {
            if (i < k - 5) flags.push_back(0);
            else flags.push_back(1);
        }

        // 구하기 
        int maxCnt = 0;
        do {
            vector<char> valid;
            for (int i = 0; i < flags.size(); i++) {
                if (flags[i] == 0) {
                    valid.push_back(alphabet[i]);
                }
            }

            // valid 에는 a,n,t,i,c 제외 문자 
            int cnt = 0;
            for (int i = 0; i < ss.size(); i++) {
                string str = ss[i];
                bool isExist = true;
                for (int j = 0; j < str.size(); j++) {
                    if (str[j] == 'a' || str[j] == 'n' || str[j] == 't' || str[j] == 'i' || str[j] == 'c') {
                        continue;
                    } else {
                        // valid 내에 존재하는 알파벳인지 
                        if (valid.size() == 0) {
                            isExist = false;
                            break;
                        }
                        
                        for (int k = 0; k < valid.size(); k++) {
                            if (str[j] == valid[k])
                                break;
                            if (k == valid.size()-1)
                                 isExist = false;
                        }
                    }
                }
                if(isExist) cnt++;
            }
            maxCnt = (maxCnt < cnt) ? cnt : maxCnt;
        } while(next_permutation(flags.begin(), flags.end()));
        cout << maxCnt;
    }

    return 0;
}