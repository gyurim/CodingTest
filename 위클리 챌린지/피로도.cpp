#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

bool visited[5005] = {false};
int n;
vector<vector<int>> dungeons;
int maxCnt = 0;
int mn = 10000;

void func(int k, int cnt) {
    // 종료 조건 필요 없음. 완전 탐색으로 ㄱㄱ 
    // if (k < mn) { // 종료 조건이 틀린 것 같다 
    //     int cnt = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (visited[j]) cnt++;
    //     }
    //     maxCnt = max(cnt, maxCnt);
    //     return;
    // }
    // 얘를 아예 없애는게 결론이었음 ;; 왜 ?? 
    // k: 80 (0, 0, 0) -> k: 60 (1, 0, 0) -> k: 20 (1, 1, 0) (이 부분을 k < mn이라 종료 조건이 되어 수행하지 않음. 그러나 k = 20까지는 수행한 다음 그 다음 단계에서 종료가 되어야한다. )
    // cout << "k: " << k << " cnt: " << cnt << endl;
    // for (int i = 0; i < n; i++)
    //     cout << i <<": " << visited[i] << " ";
    // cout << endl; 

    maxCnt = max(cnt, maxCnt);
    for (int i = 0; i < n; i++) {
        int minNeed = dungeons[i][0];
        int somo = dungeons[i][1];
    
        if (minNeed <= k && somo <= k) {
            if (!visited[i]) {
                visited[i] = true;
                int prevK = k;
                func(k-somo, cnt+1);
                k = prevK;
                visited[i] = false;
            }
        }
    }
} 

int solution(int k, vector<vector<int>> _dungeons) {
    // 냅색 ? 백트래킹 ? -> dp 문제 아니래 왜 ?? 
    n = _dungeons.size(); 
    dungeons = _dungeons;

    for (auto d : _dungeons) {
        mn = min(mn, d[0]);
    }
    func(k, 0);
    // cout << maxCnt;
    return maxCnt;
}

int main() {
    int k = 80;
    vector<vector<int>> dungeons {{80, 20}, {50, 40}, {30, 10}};
    solution(k, dungeons);
    return 0; 
}