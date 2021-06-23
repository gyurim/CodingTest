#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h>
// 못 품 

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int copyMatrix[9][9];
int matrix[9][9] = {-1};
int n, m;

void dfs(){
    
}

void setMatrix(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            copyMatrix[i][j] = matrix[i][j];
        }
    }
}
 
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    setMatrix();

    return 0;
}