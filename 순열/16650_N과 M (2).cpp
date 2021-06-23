#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int output[10];

    for (int i = 0; i < n; i++){
        if (i < m) output[i] = 0;
        else output[i] = 1;
    }
   
    do {
        for (int i = 0; i < n; i++){
            if (output[i] == 0) cout << i + 1 << ' ';
        }
    } while(next_permutation(output, output + n));

    return 0;
}