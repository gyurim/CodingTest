#include <iostream>
#include <vector>
using namespace std;

vector <int> map[21];
int n, m;
int k;

vector <int> dice = {0, 0, 0, 0, 0, 0};
// dice의 index = {아래, 북, 동, 서, 남, 위}

int currentX, currentY;

void setBottom(int direct){
    if (map[currentX][currentY] == 0){
        map[currentX][currentY] = dice[0];
    } else {
        dice[0] = map[currentX][currentY];
        map[currentX][currentY] = 0;
    }

    cout << dice[5] << "\n";
}

void setDice(int direct){
    if (direct == 1 && currentY + 1 < m) { // 동쪽 
        currentY += 1;
        dice = {dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]};   
        setBottom(direct);
    } else if (direct == 2 && currentY - 1 >= 0) { // 서쪽 
        currentY -= 1;
        dice = {dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]};
        setBottom(direct);
    } else if (direct == 3 && currentX - 1 >= 0) { // 북쪽 
        currentX -= 1;
        dice = {dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]};
        setBottom(direct);
    } else if (direct == 4 && currentX + 1 < n) { // 남쪽
        currentX += 1;
        dice = {dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]};
        setBottom(direct);
    }
}

int main(){
    cin >> n >> m >> currentX >> currentY >> k;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int num;
            cin >> num;
            map[i].push_back(num);
        }   
    }

    dice[0] = map[currentX][currentY];

    for (int i = 0; i < k; i++){
        int direct;
        cin >> direct;
        setDice(direct);
    }
}