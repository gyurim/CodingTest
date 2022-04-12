#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;

    for (int i = 1; i <= stoi(s); i++) {
        string s = to_string(i);
        if (s.size() < 3) cnt++;
        else {
            // 등차수열 판별
            bool isSequence = true;
            int dif = s[1] - s[0];
            for (int j = 1; j < s.size(); j++) {
                if (dif != (s[j] - s[j-1])) {
                    isSequence = false;
                    break;
                }
            }

            if (isSequence) cnt++;
        }
    }
    cout << cnt;
    return 0;
}