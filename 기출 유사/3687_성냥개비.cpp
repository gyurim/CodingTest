// 너무 어려움 ㅠㅠㅠㅠㅠㅠㅠ 
// max는 빨리 구했는데, min은 규칙도 안 보였음. 점화식도 안 보였음 ㅜㅜ 

#include <iostream>
#include <cstring>

using namespace std;

#define INF 0x7f // int 배열을 초기화하는 경우 0x7f7f7f7f 로 초기화됨 

// 네이버 기출 
long long num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10}; // min 값
long long minDP[101];

void minCal() {
    memset(minDP, 0x7f, sizeof(minDP));
    
    for (int i = 1; i <= 8; i++) {
        minDP[i] = num[i];
    }
    
    minDP[6] = 6; // 갯수 6의 최소 = 0(X) 6(O)
    
    for (int i = 9; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            minDP[i] = min(minDP[i], minDP[i - j] * 10 + num[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    int n; // 성냥개비 개수 
    string max, min = "";
    minCal();

    while(t--) {
        cin >> n;
        max = "";

        if (n % 2 == 0) {
            int r = n / 2;
            while (r--) {
                max += "1";
            }
        } else if (n % 2 != 0) {
            int r = n / 2 - 1;
            max = "7";
            while (r--) {
                max += "1";
            }
        }
        cout << minDP[n] << " " << max << "\n";
    }
    return 0;
}