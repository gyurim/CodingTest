#include <iostream>
using namespace std;

int d[1000005];
int dflag[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    dflag[2] = 2;
    dflag[3] = 3;

    for (int i = 4; i <= n; i++) {
        d[i] = d[i-1] + 1;
        dflag[i] = 1;

        if (i % 3 == 0) {
            if (d[i] > d[i/3] + 1) {
                dflag[i] = 3;
                d[i] = d[i/3] + 1;
            } 
        } 
        // else if라고 하면 틀림 
        if (i % 2 == 0) {
            if (d[i] > d[i/2] + 1) {
                dflag[i] = 2;
                d[i] = d[i/2] + 1;
            } 
        }
    }
    
    cout << d[n] << "\n";

    while(n != 1) {
        cout << n << " ";
        if (dflag[n] == 1) n--;
        else if (dflag[n] == 2) n /= 2;
        else n /= 3;
    }
    cout << n;
    return 0;
}