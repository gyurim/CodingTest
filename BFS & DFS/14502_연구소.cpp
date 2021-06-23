#include <iostream>
#include <vector>
using namespace std;

/*
다음 기회에 ... ^^~ 
*/

vector<vector<int>> area;

void setSafeWall(int areaX, int areaY){
    vector<vector<int>> copyArea;
    
    copy(area.begin(), area.end(), copyArea.begin());

}

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int status;
            cin >> status;
            area[i].push_back(status);
        }
    }

    setSafeWall(n, m);
}