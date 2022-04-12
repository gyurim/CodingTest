// 구글링 참조
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
int n;
int score[20][20] = {};
bool team[20] = {};
int diffmin = 99999999;

void teamset(int idx, int cnt) {
    vector<int> start; 
    vector<int> link;

    int start_score = 0;
    int link_score = 0;

    if (cnt == n / 2) {
        for (int i = 0; i < n; i++) {
            if (team[i] == true) start.push_back(i); // 선택된 사람들은 start 팀에 
            else link.push_back(i); // 그 외의 사람들은 link 팀에 
        }

        for (int i = 0; i < (n/2); i++) {
            for (int j = 0; j < (n/2); j++) {
                start_score += score[start[i]][start[j]];
                link_score += score[link[i]][link[j]];
            }
        }

        diffmin = min(abs(start_score - link_score), diffmin);
        return;
    }

    for (int i = idx; i < n; i++) {
        if (team[i]) continue;
        else {
            team[i] = true;
            teamset(i, cnt+1);
            team[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> score[i][j];
        }
    }
    teamset(0, 0);
    cout << diffmin;
    return 0;
}