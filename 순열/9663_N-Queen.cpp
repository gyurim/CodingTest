#include <iostream>
#include <stdlib.h>

using namespace std;

int arr[15] = {-1};
int cnt = 0;
int n;

/*
절대값을 구할 수 있는 절대값 함수 abs
선언 안 해도 되지만, 이상한 점 존재 

#include <cstdlib> : int 타입의 정수 절대값 함수
#include <cmath> : float, double 타입의 정수 절대값 함수 
*/

int promising(int cdx){
    for (int i = 0; i < cdx; i++){
        if (arr[cdx] == arr[i] || cdx - i == abs(arr[cdx] - arr[i]))
            return 0; // 유망하지 X 
    }
    return 1; // 유망 
}

void dfs(int cdx){ // cdx == 행 
    if (cdx == n){
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++){
        arr[cdx] = i;
        if (promising(cdx)){
            dfs(cdx + 1);
        }
    }
}

int main(){
    cin >> n;

    // 이차원 배열 필요 없음. -> 일차원배열의 index는 행, index 속 값은 열 
    dfs(0);
    cout << cnt;
    return 0;
}