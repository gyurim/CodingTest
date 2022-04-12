#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int city[51][51];
vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;

int getDistance(vector<pair<int, int>> selected) {
    int totalDistance = 0;
    for (int i = 0; i < homes.size(); i++) {
        int minChickenDistance = 987654321;
        for (int j = 0; j < selected.size(); j++) {
            int distance = abs(homes[i].first-selected[j].first) + abs(homes[i].second-selected[j].second);
            minChickenDistance = (minChickenDistance > distance) ? distance : minChickenDistance;
        }
        totalDistance += minChickenDistance;
    }
    return totalDistance;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                homes.push_back({i, j});
            } else if (city[i][j] == 2) {
                chickens.push_back({i, j});
            }
        }
    }
    vector<int> flags;
    for (int i = 0; i < chickens.size(); i++) {
        if (i < m) flags.push_back(0);
        else flags.push_back(1);
    }
    int minTotalChickenDistance = 987654321;
    do {
        vector<pair<int, int>> selected;
        for (int i = 0; i < flags.size(); i++) {
            if (flags[i] == 0) {
                // 거리 계산 
                selected.push_back(chickens[i]);   
            }
        }
        int totalDistance = getDistance(selected);
        minTotalChickenDistance = (minTotalChickenDistance > totalDistance) ? totalDistance : minTotalChickenDistance;

    } while (next_permutation(flags.begin(), flags.end()));
    cout << minTotalChickenDistance;
    return 0;
}