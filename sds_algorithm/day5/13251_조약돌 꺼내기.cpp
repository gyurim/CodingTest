#include <iostream>
using namespace std;

/*
처음에는 분자에 가능한 모든 경우의 수를 더해놓고 마지막에 분모와 나누어주었는데, 
그렇게 하면 long long의 범위조차 벗어난다. 
따라서, 연속해서 a 컬러를 뽑는 확률 + 연속해서 b 컬러를 뽑는 확률 ... 구함.

m = 5, k = 2
2/5 * 1/4 -> 연속해서 a 컬러만 2개 뽑을 경우  
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, k, n = 0;
    int stone[51];

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> stone[i];
        n += stone[i];
    }
    cin >> k;

    double ans = 0;

    for (int i = 0; i < m; i++) {
        double total = 1.0;
        int deo = n; // 분자 
        int num = stone[i];
        for (int j = 0; j < k; j++) {
            total *= ((double)num/deo);
            num--;
            deo--;
        }
        ans += total;
    }
    if (ans == 1) cout << "1.0";
    else {
        cout << fixed;
        cout.precision(18);
        cout << ans; 
    }
    return 0;
}