#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    int sum = 0;
    // 입력되는 정수의 절댓값은 4,000을 넘지 않는다. 
    int cnt[8001] = {0};
    int max = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
        sum += num;
        cnt[num+4000]++;
        max = (max < cnt[num+4000]) ? cnt[num+4000] : max;
    }

    sort(vec.begin(), vec.end());
    // 1. 산술 평균 
    cout << round(sum / n) << '\n';
    // 2. 중앙값 
    cout << vec[n/2] << '\n';
    // 3. 최빈값 
    int value = 0;
    bool isSecond = false;
    for (int i = -4000; i < 4001; i++) {
        if (max == cnt[i + 4000]) {
            value = i;
            if (isSecond) break;
            isSecond = true;
        }
    }
    cout << value;
    // 4. 최댓값 - 최솟값
    cout << vec[n-1] - vec[0];
    return 0;
}