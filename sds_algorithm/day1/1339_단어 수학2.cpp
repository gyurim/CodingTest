#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> alphabet;
pair<char, pair<int, int>> idxAndCnt[50];
vector<string> words;

// cmp가 내가 원하는 방식으로 작동 안됨.. ㅠ 
bool cmp(const pair<char, pair<int, int>>& a, const pair<char, pair<int, int>>& b) {
    if (a.second.first == b.second.first) {
        if (a.second.second == b.second.second) {
            return a.first < b.first;
        }
        return a.second.second < b.second.second;
    }
    return a.second.first < b.second.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;

        for (int j = 0; j < word.size(); j++) {
            auto it = find(alphabet.begin(), alphabet.end(), word[j]);
            if (it == alphabet.end()) {
                // 알파벳 존재 X 
                alphabet.push_back(word[j]);
                idxAndCnt[word[j]-'A'] = {word[j], {word.size()-j, 1}};
                
            } else {
                if (word.size()-j > idxAndCnt[word[j]-'A'].second.first) {
                    idxAndCnt[word[j]-'A'].second.first = word.size()-j;
                }
                idxAndCnt[word[j]-'A'].second.second++;
            }
        }
        words.push_back(word);
    }

    sort(idxAndCnt, idxAndCnt + 50, cmp);

    return 0;
}