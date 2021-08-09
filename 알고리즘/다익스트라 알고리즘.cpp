//----------------------------------------------------------------------
// 방법 1
//----------------------------------------------------------------------
// 모든 노드를 처음부터 끝까지 다 탐색하는 선형 탐색으로 구현
// 시간복잡도 = O(N^2)
// 따라서 이렇게 하면 안됨
//----------------------------------------------------------------------

#include <stdio.h>

int number = 6;
int INF = 1000000000; // int형은 약 21억 정도의 양수값을 가질 수 있기 때문에 10억으로 넣어줘도 무난하게 무한이라는 수치 표현 가능 

// 그래프 초기화 
int a[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};

bool v[6]; // 방문한 파악
int d[6]; // 최단 거리 

// 가장 최소 거리를 가지는 정점을 반환
int getSmallIndex() {
    int min = INF;
    int index = 0; 
    for (int i = 0; i < number; i++) {
        if (d[i] < min && !v[i]) {
            min = d[i];
            index = i;
        }
    }
    return index;
}

// 다익스트라를 수행하는 함수
void dijkstra(int start) {
    for (int i = 0; i < number; i++) {
        d[i] = a[start][i]; // 시작정점으로부터 출발했을때 모든 경로까지의 비용을 담아줄 수 있으면 됨
    }

    v[start] = true;
    for (int i = 0; i < number - 2; i++) {
        // 현재 방문하지 않은 노드 중에서 빠르게 도착할 수 있는 (= 최소 비용을 가지는) 노드의 인덱스를 가져온다.
        int current = getSmallIndex();
        v[current] = true;
 
        for (int j = 0; j < 6; j++) {
            // current 노드에 인접한 모든 노드들을 확인해보면서, 방문하지 않은 노드 중 해당 노드까지의 경로가 (1. current를 거쳐서 목적 노드로 가는 경로 2. 목적 노드로 가는 기존 경로) 2보다 1이 작다면 최소비용을 갱신
            if (!v[j]) { 
                d[j] = (d[current] + a[current][j] < d[j]) ? d[current] + a[current][j] : d[j];
            }
        }
    }
}

//----------------------------------------------------------------------
// 방법 2
//----------------------------------------------------------------------
// 힙 사용
// 가장 작은 값을 가져오는 getSmallIndex() 과정이 O(logN) 시간 복잡도 가지게 됨
// 시간 복잡도 = O(NlogN)
// 우선 순위 큐는 heap 구조와 내부적으로 같게 동작 
//----------------------------------------------------------------------
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int>> a[7]; // 간선 정보
int d[7]; // 최소 비용 

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq; // 힙 구조
    // 가까운 순서대로 처리하므로 큐를 사용
    while(!pq.empty()) {
        int current = pq.top().first; // 큐의 top에는 가장 적은 비용을 가지는 노드에 대한 정보가 들어있음. 
        // priority queue는 기본적으로 더 큰 값을 기준으로 최상단 노드를 만든다. -> 즉, 최대힙
        // 그러나, 최소 비용이 더 적은 값이 상단 노드로 가야하기 때문에 짧은 것이 먼저 오도록 음수화(-)한다. 

        int distance = -pq.top().second; // (이미 값들이 음수화돼서 저장되어있음)
        pq.pop();
        //최단 거리가 아닌 경우 스킵함.
        if (d[current] < distance) continue; // 갱신된 상태라면 무시 
        for (int i = 0; i < a[current].size(); i++) {
            // 선택된 노드의 인접노드
            int next = a[current][i].first;
            // 선택된 노드를 거쳐서 인접 노드로 가는 비용
            int nextDistance = distance + a[current][i].second;
            // 기존의 최소 비용보다 더 저렴하다면 교체
            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}

int main() {
    // 기본적으로 연결되지 않은 경우 비용은 무한
    for (int i = 1; i <= number; i++) {
        d[i] = INF;
    }

    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    a[1].push_back(make_pair(4, 1));

    a[2].push_back(make_pair(1, 2));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(4, 2));

    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(2, 3));
    a[3].push_back(make_pair(4, 3));
    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(6, 5));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(5, 1));

    a[5].push_back(make_pair(3, 1));
    a[5].push_back(make_pair(4, 1));
    a[5].push_back(make_pair(6, 2));

    a[6].push_back(make_pair(3, 5));
    a[6].push_back(make_pair(5, 2));

    dijkstra(1);
    
    // 결과 출력
    for(int i = 1; i <= number; i++) {
        printf("%d ", d[i]);
    }
}
