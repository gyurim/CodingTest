#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int alphabet[26];
vector<string> v;

bool cmp(int a, int b) {
    if (a > b) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        v.push_back(word);
    }

    for (int i = 0; i < n; i++) {
        string s = v[i];
        int len = s.length();
        int pow = 1;

        for (int j = len - 1; j >= 0; j--) {
            int tmp = s[j] - 'A';
            alphabet[tmp] = alphabet[tmp] + pow;
            pow *= 10; // 자릿수 ++ 
        }
    }

    sort(alphabet, alphabet + 26, cmp);

    int answer = 0;
    int num = 9;

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0) break;
        answer = answer + (alphabet[i] * num);
        num--;
    }
    cout << answer;
    return 0;
}