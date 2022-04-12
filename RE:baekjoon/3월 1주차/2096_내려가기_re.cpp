#include <iostream>
#include <algorithm>
using namespace std;

int arr[4];
int minarr[4];

int main() {
    int n;
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (i == 0) {
            arr[0] = a;
            arr[1] = b;
            arr[2] = c;

            minarr[0] = a;
            minarr[1] = b;
            minarr[2] = c;
        } else {
            // max 
            int tmp0 = arr[0];
            int tmp1 = arr[1];
            arr[0] = max(arr[0], arr[1]) + a;
            arr[1] = max(tmp0, max(tmp1, arr[2])) + b;
            arr[2] = max(tmp1, arr[2]) + c;

            // min
            tmp0 = minarr[0];
            tmp1 = minarr[1];
            minarr[0] = min(minarr[0], minarr[1]) + a;
            minarr[1] = min(tmp0, min(minarr[1], minarr[2])) + b;
            minarr[2] = min(tmp1, minarr[2]) + c;
        }
    }

    cout << max(arr[0], max(arr[1], arr[2])) << " ";
    cout << min(minarr[0], min(minarr[1], minarr[2])) << endl;

    return 0;
}