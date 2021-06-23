#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    int a[12];    
    int opNum[5];
    vector <int> op;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for (int i = 0; i < 4; i++){
        cin >> opNum[i];

        for (int j = 0; j < opNum[i]; j++){
            op.push_back(i);
            // 0: +
            // 1: -
            // 2: *
            // 3: /
        }
    }

    vector<int> result;

    do {
        int sum = a[0];
        for (int i = 1; i < n; i++){
            if (op[i-1] == 0)
                sum += a[i];
            else if (op[i-1] == 1)
                sum -= a[i];
            else if (op[i-1] == 2)
                sum *= a[i];
            else if (op[i-1] == 3)
                sum /= a[i];
        }
        result.push_back(sum);
    } while (next_permutation(op.begin(), op.end()));

    
    int min = result[0];
    int max = result[0];
    for (int i = 0; i < result.size(); i++){
        if (result[i] >= max)
            max = result[i];
        if (result[i] <= min)
            min = result[i];
    }
    
    cout << max << "\n";
    cout << min;
      
    return 0;
}