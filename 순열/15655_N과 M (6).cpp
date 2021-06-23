#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[10];
    int isFlag[10];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++){
        if (i < m) isFlag[i] = 0;
        else isFlag[i] = 1;
    }

    do {
        for (int i = 0; i < n; i++){
            if (isFlag[i] == 0) cout << arr[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(isFlag, isFlag + n));

    return 0;
}