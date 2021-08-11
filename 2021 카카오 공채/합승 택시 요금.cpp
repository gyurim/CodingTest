//-----------------------------------------------------------------------------------------------------
// 방법 1
//-----------------------------------------------------------------------------------------------------
// 플로이드 와샬 알고리즘 
// dist(A, K) + dist(B, K) + dist(S, K) => A와 B가 K까지 같이 간 뒤 찢어진다면, 해당 값은 이 식처럼 됨.
// 따라서 K를 1부터 N까지 다 넣어보면 됨
// 시간복잡도 = O(V^3)
//-----------------------------------------------------------------------------------------------------
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int d[205][205];
// int INF = 1e8 + 10;
int INF = 100000000;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 1; i <= n; i++) 
        fill(d[i], d[i]+1+n, INF);
    
    for (auto v : fares) {
        d[v[0]][v[1]] = v[2];
        d[v[1]][v[0]] = v[2];
    }

    for (int i = 1; i <= n; i++) 
        d[i][i] = 0;
    
    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    
    int ans = INF;
    for (int mid = 1; mid <= n; mid++) 
        ans = min(ans, d[s][mid] + d[mid][a] + d[mid][b]);

    return ans;
}

//-----------------------------------------------------------------------------------------------------
// 방법 2
//-----------------------------------------------------------------------------------------------------
// 다익스트라 알고리즘
// 시간복잡도 = O(ElogE)
//-----------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using pill = pair<int, int>;

int d[3][205];
int INF = 1000000000;
vector<pill> adj[205];

void dijkstra(int st, int idx) {
    priority_queue<pill, vector<pill>, greater<pill>> pq;
    fill(d[idx], d[idx]+201, INF);

    d[idx][st] = 0;
    pq.push({d[idx][st], st});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int dist = cur.first, i = cur.second;
        if (d[idx][i] != dist) continue;
        for (auto nxt : adj[i]) {
            int cost = nxt.first, ni = nxt.second;
            if(d[idx][ni] > dist + cost) {
                d[idx][ni] = dist + cost;
                pq.push({d[idx][ni], ni});
            }
        } 
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (auto v : fares) {
        adj[v[0]].push_back({v[2], v[1]});
        adj[v[1]].push_back({v[2], v[0]});
    }
    dijkstra(s, 0);
    dijkstra(a, 1);
    dijkstra(b, 2);
    int ans = INF;
    for (int mid = 1; mid <= n; mid++) {
        ans = min(ans, d[0][mid] + d[1][mid] + d[2][mid]);
    }
    return ans;
}

//----------------------------------------------------------------------
// 내가 짠 잘못된 코드 
//----------------------------------------------------------------------
/*
#include <algorithm> 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> setRoute(int s, int e, int w[200][200]) {
    int start = s;
    int end = e;
    vector<int> route;
    route.push_back(e);

    while(true) {
        if (w[start][end] == start) {
            break;
        } else {
            route.push_back(w[start][end]);
            end = w[start][end];
        }
    }
    route.push_back(start);
    
    return route;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int INF = 1000000;

    int d[200][200]; 
    int w[200][200];

    // int w[200][200] = {-1}; 2차원 배열 초기화 이렇게 하지 말고 (값 제대로 안들어감)
    // 2중 for문 사용해서 하기 ㅠㅠ -> 외우기!! 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = -1;
            w[i][j] = -1;
        } 
    }
    
    // 결과 그래프를 초기화 
    for (int i = 0; i < fares.size(); i++) {
        int start = fares[i][0];
        int end = fares[i][1];

        d[start][end] = fares[i][2];
        d[end][start] = fares[i][2];
        w[start][end] = start;
        w[end][start] = end;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else if (d[i][j] == -1) d[i][j] = INF;
        }
    }

    // 거쳐가는 노드를 기준으로 플로이드 와샬 작동함 
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    // 최단 경로 가중치 갱신
                    d[i][j] = d[i][k] + d[k][j];
                    // 직전 노드 수정 (경로 갱신)
                    w[i][j] = w[k][j]; // k 대입 X (헷갈;)
                    
                    //1 -> ? -> 4 —> 5 라 가정
                    //1 —> 5 경로에 k값을 그대로 넣으면 직전 경로가 아니게 됨.
                    //4 —> 5 경로가 4 -> 3 -> 5 
                    //따라서, 1 —> 5 에는 4 —> 5 직전 노드인 3이 직전 노드로 설정되어야함.
                }     
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << w[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> ar = setRoute(s, a, w);
    reverse(ar.begin(), ar.end());
    vector<int> br = setRoute(s, b, w);
    reverse(br.begin(), br.end());

    bool canTogether = true;

    if (ar.size() > br.size()) {
        for (int i = 0; i < br.size(); i++) {
            if (ar[i] == br[i] && ar[i+1] == br[i+1] && canTogether) {
                answer += fares[ar[i]][ar[i+1]];
                cout << fares[ar[i]][ar[i+1]] << " ";
            }
            else {
                canTogether = false;
                answer += fares[ar[i]][ar[i+1]];
                answer += fares[br[i]][br[i+1]];    
                cout << fares[ar[i]][ar[i+1]] << " ";
                cout << fares[br[i]][br[i+1]]  << " ";
            }
            
        }
        for (int i = br.size(); i < ar.size()-1; i++) {
            answer += fares[ar[i]][ar[i+1]];
            cout << fares[ar[i]][ar[i+1]] << " ";
        }
    } else {
        for (int i = 0; i < ar.size(); i++) {
            if (ar[i] == br[i] && ar[i+1] == br[i+1] && canTogether) {
                answer += fares[ar[i]][ar[i+1]];
                cout << fares[ar[i]][ar[i+1]] << " ";
            }
            else {
                canTogether = false;
                answer += fares[ar[i]][ar[i+1]];
                answer += fares[br[i]][br[i+1]];    
                cout << fares[ar[i]][ar[i+1]] << " ";
                cout << fares[br[i]][br[i+1]]<< " ";
            }
        }

        for (int i = ar.size(); i < br.size()-1; i++) {
            answer += fares[br[i]][br[i+1]];   
            cout << fares[br[i]][br[i+1]]<< " ";
        }
            
    }
    
    cout << answer;
    
    return answer;
}

int main() {
    vector<vector<int>> fares;
    int arr[201][201] = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    
    vector<int> vec;
    vec.push_back(arr[0][0]);
    
    for (int i = 0; i < 9; i++) {
        vector<int> vec;
        vec.push_back(arr[i][0]);
        vec.push_back(arr[i][1]);
        vec.push_back(arr[i][2]);

        fares.push_back(vec);
    }

    solution(6, 4, 6, 2, fares);
    return 0;
}
*/