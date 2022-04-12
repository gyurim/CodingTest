#include <iostream>
#include <vector>
using namespace std;

// 바킹독 코드 
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> state(n+1, true); 

    // state 배열을 vector<int>, bool 배열로 두기 보다는 vector<bool>로 두는 것이 공간, 시간 측면에서 좋음
    // bool은 1 char 크기 즉, 1 byte. 
    // 그런데 vector<bool>로 두면, bool 한 칸이 1 byte가 아니라 1 bit만 차지하게 최적화가 이루어짐
    // 이 최적화 덕분에 공간도 8배 적게 쓰고, cache hit rate가 올라가서 시간도 빨라짐. 

    state[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!state[i]) continue;
        for (int j = 2 * i; j <= n; j += i) 
            state[j] = false;
    }
    for (int i = 2; i <= n; i++)
        if (state[i]) primes.push_back(i);

    return primes;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    bool matrix[1005];
    fill_n(matrix, n+1, true); // 초기화 
    matrix[1] = false;

    int cnt = 0;
    bool isFind = false;

    for (int i = 2; i <= n; i++) {
        if (matrix[i]) { // 소수
            for (int j = 1; i * j <= n; j++) {
                if (matrix[i*j]) {
                    matrix[i*j] = false;
                    cnt++;

                    if (cnt == k) {
                        cout << i * j << '\n';
                        isFind = true;
                        break;
                    }
                }
            }
        }
        if (isFind) break;
    }
    return 0;
} 