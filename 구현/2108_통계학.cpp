#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec;
    map<int, int> m;
    int num;
    double sum = 0;
    int maxCnt = 1;
    for (int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
        sum += num;

        auto it = m.find(num);
        if (it != m.end()) {
            it->second++;
            maxCnt = max(maxCnt, it->second);
        }
        else m.insert({num, 1});

    }
    // cout << endl;
    // 1. 산술평균 - 첫째자리에서 반올림 
    int average = round(sum/n); 
    if (average == -0 || average == 0) // round(sum/n) = -0 이 나왔음;; 예외처리 
        cout << 0 << "\n";
    else 
        cout << average << "\n";
    
    sort(vec.begin(), vec.end());
    // 2. 중앙값 
    cout << vec[n/2] << "\n";
    // 3. 최빈값
    vector<int> maxVec;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == maxCnt) maxVec.push_back(it->first);
    }
    if (maxVec.size() == 1) 
        cout << maxVec[0] << "\n";
    else {
        sort(maxVec.begin(), maxVec.end());
        cout << maxVec[1] << "\n";
    }

    // 4. 범위
    cout << vec[vec.size()-1] - vec[0];
    return 0;
}