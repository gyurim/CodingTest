// 방법 1
// 효율성 테스트 
#include <string>
#include <vector>
#include <queue> // priority queue 사용 
#include <iostream>
#include <functional> // greater 사용 

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap; // 최소 힙 (오름차순)
    // priority_queue<int> max_heap; // 최대 힙 (내림 차순 )

    for (int i = 0; i < scoville.size(); i++) {
        min_heap.push(scoville[i]);
    }

    while(1) {
        if (min_heap.top() < K && min_heap.size() > 1) {
            int temp = min_heap.top();
            min_heap.pop();
            int temp2 = min_heap.top();
            min_heap.pop();
            int re = temp + temp2*2;
            min_heap.push(re);
            answer++;
        } else break;
    }

    if (min_heap.top() < K) answer = -1;

    return answer;
}

// 방법 2
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// int solution(vector<int> scoville, int K) {
//     int answer = 0;
//     int i = 0;

//     while(1) {
//         sort(scoville.begin(), scoville.end());

//         if (scoville[i] < K && i < scoville.size() - 1) {
//             scoville[i] = scoville[i] + scoville[i+1] * 2;
//             scoville.erase(scoville.begin() + i + 1);
//             i = 0;
//             answer++;
//         } else break;
//     }

//     // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우 -1 리턴 
//     sort(scoville.begin(), scoville.end());
//     if (scoville[0] < K) {
//         answer = -1;
//     }

//     return answer;
// }