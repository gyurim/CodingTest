#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; 

    int x[1000001];
    int xp[1000001];
    vector<int> sortx;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        xp[i] = x[i];
    }

    sort(x, x + n);

    // 중복 제거 방법 1
    // int cur = x[0];
    // sortx.push_back(cur);

    // for (int i = 1; i < n; i++) {
    //     if (cur != x[i]) {
    //         cur = x[i];
    //         sortx.push_back(cur);
    //     }
    // }
    
    // 중복 제거 방법 2 
    sortx.erase(unique(sortx.begin(), sortx.end()), sortx.end()); 
    // unique 함수를 수행하면 sortx 배열에서 unique한 애들을 앞으로 모아주고 중복된 애들을 맨 뒤에 쓰레기값으로 보냄 (이때, 쓰레기 값이 시작되는 iterator를 리턴). 
    // 따라서 erase 함수과 함께 사용해서 해당 쓰레기 값이 들어간 iterator가 가리키는 부분에서 end까지 지워주면 중복 제거 완료 

    // 좌표 압축 결과는 sortx 배열을 이분 탐색하면 끝 
    for (int i = 0; i < n; i++) {
        int result = lower_bound(sortx.begin(), sortx.end(), xp[i]) - sortx.begin();
        cout << result << " ";
    }
    return 0;
}