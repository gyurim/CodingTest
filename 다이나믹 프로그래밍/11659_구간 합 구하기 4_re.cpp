// 2022.04.15

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    long long sum[100005];
    memset(sum, 0, sizeof(sum));

    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum[i] = sum[i-1] + num;
    }
    int a, b;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n"; 
    }
    return 0;
}