#include <iostream>
#include <vector>
#include <stdio.h> // scanf, printf
 
using namespace std;

vector<int> a_arr;
vector<int> b_arr;

int n, m;

bool isBiggerA(int i, int j) {
    if (i == n) return false;
    if (j == m) return true; 

    if (a_arr[i] > b_arr[j]) return false;
    else if (a_arr[i] <= b_arr[j]) return true;
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a_arr.push_back(num);
    }

    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        b_arr.push_back(num);
    }

    // merge sort 
    int a_idx = 0;
    int b_idx = 0;

    while (!(a_idx == n && b_idx == m)) {
        
        if (isBiggerA(a_idx, b_idx)) {
            printf("%d ", a_arr[a_idx]);
            if (a_idx < n) a_idx++;
        }
        else {
            printf("%d ", b_arr[b_idx]);
            if (b_idx < m) b_idx++;
        }
    }    
    return 0; 
}