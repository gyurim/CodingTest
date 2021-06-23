#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

/*
cin, cout에서 시간 초과 떠서 scanf, printf 사용해야함.
필요한 헤더: #include <cstdio>
*/

int main(){
    int n, m;
    vector <int> a;
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int aNum;
        scanf("%d", &aNum);
        a.push_back(aNum);
    }

    sort(a.begin(), a.end());

    scanf("%d", &m);
    
    for(int i = 0; i < m; i++){
        int key;
        scanf("%d", &key);
        if (binary_search(a.begin(), a.end(), key)){
            // binary_search 사용하려면 #include <algorithm>
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}