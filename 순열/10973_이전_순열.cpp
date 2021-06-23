#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    vector <int> v;
    cin >> n;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    bool flag = prev_permutation(v.begin(), v.end());
    // 만약 이전 순열이 없다면 flag = FALSE 리턴 

    if (flag){
        for (int i = 0; i < n; i ++){
            cout << v[i] << " ";
        }
    } else cout << "-1";

    return 0; 
}