#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int city[50][50] = {0};
int n, m;
int cnt = 0;

vector<pair<int, int>> chickenLocation;
vector<pair<int, int>> homeLocation;

/* 호출한 함수 내에서 vector 값을 바꾸고 싶으면 
vector를 call by value가 아닌 call by reference(참조에 의한 호출)를 이용해야한다. */
int getDistance(vector<pair<int, int>> &chickens){
    int totalMinimum = 0;

   for (int i = 0; i < homeLocation.size(); i++){
        int min = abs(homeLocation[i].first-chickens[0].first) + abs(homeLocation[i].second - chickens[0].second);
        // int min = 999;
        for (int j = 0; j < chickens.size(); j++){            
            int differ = abs(homeLocation[i].first-chickens[j].first) + abs(homeLocation[i].second - chickens[j].second);
            if (differ <= min) min = differ;
        }
        totalMinimum += min;
    }
    return totalMinimum;
}

void printChickenStreet(){
    vector <int> minimum; 

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (city[i][j] == 2){
                chickenLocation.push_back(make_pair(i, j));
            }

            if (city[i][j] == 1) {
                homeLocation.push_back(make_pair(i, j));
            }
        }
    }

    vector <int> combChicken;
    for (int i = 0; i < chickenLocation.size(); i++){
        if (i < m) {
            combChicken.push_back(1);
        }
        else {
            combChicken.push_back(0);
        }
    }
    sort(combChicken.begin(), combChicken.end());
    // sort 안해줘서 시간 개많이 뺏김; 
    // -> 1을 먼저 넣어주는 상황이니까 순열의 끝이라고 판단해 바로 끝남;; 
    do {
        vector<pair<int, int>> chickens;
        // 순열말고 조합으로 가야함. 354 453 453 다 다른 것으로 판정하기 때문에 
        for (int i = 0; i < combChicken.size(); i++){
            if (combChicken[i] == 1) {
                chickens.push_back(chickenLocation[i]);
            }
        }
        minimum.push_back(getDistance(chickens));
    } while (next_permutation(combChicken.begin(), combChicken.end()));

    int min = *min_element(minimum.begin(), minimum.end());
    // min_element는 최소값의 주소를 반환! 따라서, 값으로 받기 위해서는 포인터 사용! 
    cout << min;
}

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> city[i][j];
        }
    }
    printChickenStreet();
    return 0;
} 