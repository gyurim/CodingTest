// 핵심: 시간이 빨라도 늦게 끝나면 최대 회의의 수를 맞출 수 없음 
// 따라서 각각의 스케줄에서 회의의 종료시간이 중요하게 작용함 

// 지금은 손해더라도 나중에 이득을 취할 수 있는 상황은 없는지 확인해보기
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> schedule(n);
    int st, en;
    for (int i = 0; i < n; i++) {
        cin >> st >> en;
        schedule[i].push_back(en);// 정렬 쉽게 하기 위함 
        schedule[i].push_back(st);
    }

    sort(schedule.begin(), schedule.end()); // 끝나는 시간이 동일할 경우, 시작 시간이 더 빠른 것부터 처리해주기 위함

    int en = schedule[0][0];
    int cnt = 1;

    for (int i = 1; i < n; i++) {        
        if (en <= schedule[i][1]) { // 이전 회의의 종료시간보다 시작하려는 회의의 시작 시간이 크거나 같으면 됨 
            cnt++;
            en = schedule[i][0];
        }
    }
    cout << cnt;
    return 0;
}

/*
// 시간 초과 
// 처음부터 일단 넣어서 뒤에 스케줄들이 들어갈 수 있는지 체크해 cnt를 증가시키기 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 100005

int ltime[INF][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    memset(ltime, 0, sizeof(ltime));
    int max_time = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> ltime[i][0] >> ltime[i][1];
        max_time = max(ltime[i][1], max_time);
    }
    
    int max_cnt = 0;
    
    for (int i = 0; i < n; i++) {
        int st = ltime[i][0];
        int en = ltime[i][1];
        int cur = i + 1;
        int cnt = 1;
        // cout << i << " ";
        while(cur < n) {
            if (ltime[cur][0] >= en && ltime[cur][0] >= st && ltime[cur][1] >= st && ltime[cur][1] >= en) {
                cnt++;
                st = ltime[cur][0];
                en = ltime[cur][1];
                // cout << cur << " ";
            }
            cur++;
        }
        max_cnt = max(max_cnt, cnt);
        // cout << endl;
    }
    cout << max_cnt;
    return 0;
}
*/
/*
// 시간 초과
// 백트래킹 
#include <iostream>
#include <cstring>

using namespace std;

int ltime[100005][3];
int max_cnt = 0;
int n;
bool visited[100005] = {false};

void func(int l, int cnt) {
    // l : 현재 회의 
    int l_st = ltime[l][0];
    int l_en = ltime[l][1];
    max_cnt = max(cnt, max_cnt);
    
    for (int i = 0; i < n; i++) {
        if (i == l) continue;
        if (ltime[i][0] >= l_en && !visited[i]) {
            max_cnt = max(cnt, max_cnt);
            visited[i] = true;
            func(i, cnt+1);
            visited[i] = false;
        }
    }
}

int main(){
    
    cin >> n;
    memset(ltime, 0, sizeof(ltime));
    
    for (int i = 0; i < n; i++) {
        cin >> ltime[i][0] >> ltime[i][1];
    }
    func(0, 1);
    cout << max_cnt;
    return 0;
}
*/