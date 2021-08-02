#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int info[52][52];

vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<int> isSelected;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> info[i][j];
            
            if (info[i][j] == 1) 
                home.push_back(make_pair(i, j));
            else if (info[i][j] == 2) 
                chicken.push_back(make_pair(i,j));
        }
    }  

    for (int i = 0; i < chicken.size(); i++) {
        if (m > i) isSelected.push_back(0);
        else isSelected.push_back(1);
    }

    /*
    vector<int> isSelected(chicken.size(), 0);
    fill(isSelected.begin(), isSelected.begin() + chicken.size() - m, 1);

    // m = 2, chicken.size() = 5 -> 0 0 1 1 1 
    */

    int minNum = 0x7f7f7f7f;

    do {
        int cityDistance = 0;
        for (int i = 0; i < home.size(); i++) {
            int minChicken = 0x7f7f7f7f;
            for (int j = 0; j < isSelected.size(); j++) {
                if (isSelected[j] == 0) {
                    int chickenDistance = abs(chicken[j].first - home[i].first) + abs(chicken[j].second - home[i].second);
                    minChicken = min(chickenDistance, minChicken);
                }
            }
            cityDistance += minChicken;
        }
        minNum = min(minNum, cityDistance);
    } while(next_permutation(isSelected.begin(), isSelected.end()));

    cout << minNum; 
    return 0;
}