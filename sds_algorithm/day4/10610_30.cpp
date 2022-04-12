#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 30의 배수 
/*
3의 배수: 각 자리 수의 합이 3의 배수라면 해당 수는 3의 배수이다. 
10의 배수: 마지막 자리가 0이면 10의 배수 

따라서 3의 배수, 10의 배수 조건을 갖추면 됨. 
*/

int main() {
    string n;
    cin >> n;

    vector<int> vec;

    long long sum = 0;

    for (int i = 0; i < n.length(); i++) {
        vec.push_back(n[i]-'0');
        sum += (n[i] - '0'); 
    }

    if (sum % 3 != 0) 
        cout << "-1";
    else {
        sort(vec.begin(), vec.end(), greater<int>());
        if (vec[vec.size()-1] != 0) 
            cout << "-1";
        else {
            for (int i = 0; i < vec.size(); i++) {
                cout << vec[i];
            }
        }
    }    
    return 0;
}