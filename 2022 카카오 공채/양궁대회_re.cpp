// 2022.04.22 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 1. 그리디 풀이
// a가 b보다 더 좋은 배치일 경우 true  
bool cmp(vector<int>& a, vector<int>& b){
    for (int i = 11; i >= 0; i--) 
        if (a[i] != b[i]) return a[i] > b[i];
    return false;
} 

vector<int> solution(int n, vector<int> info) {
    // 라이언이 가장 큰 점수 차이로 우승할 수 있는 결과를 저장 
    // ret[0..10]
    // -> 10-i점에서 라이언이 맞힌 화살의 수 
    // ret[11] : 점수 차이 
    vector<int> ret(12, -1);
    // 라이언은 자신이 승리할 점수를 선택 
    // brute = 1100100001 (2) 이면 10, 5, 2, 1점에서 이길 것임을 의미 
    for (int brute = 0; brute < 1024; brute++) {
        vector<int> arrow(12);
        int score = 0;
        int left = n; // 남아있는 화살의 수 

        for (int i = 0; i < 10; i++) {
            // i번째 비트가 켜져 있는 경우 (10-i점에서 승리할 계획)
            if (brute & (1 << i)) {
                score += (10-i);
                left -= (info[i] + 1);
                arrow[i] = info[i] + 1;
            }

            // i번째 비트가 꺼져 있는 경우(10-i점에서 패배할 계획)
            // 어피치가 1개라도 맞췄으면 점수에 반영 
            else if (info[i] != 0) {
                score -= (10 - i);
            }
        }
        // 라이언의 점수가 높지 않거나 화살을 n발 초과로 쏜 경우
        if (score <= 0 || left < 0) continue;
        arrow[10] = left;
        arrow[11] = score;
        // arrow가 기존에 저장된 ret보다 좋을 경우
        if (cmp(arrow, ret)) ret = arrow;
    }
    if (ret[0] == -1) return vector<int>((-1));
    ret.pop_back();
    return ret;
    
}

// 2. 시뮬레이션 풀이 
/*
// a가 b보다 더 좋은 배치일 경우 true 
bool cmp(vector<int>& a, vector<int>& b){
    for (int i = 11; i >= 0; i--) 
        if (a[i] != b[i]) return a[i] > b[i];
    return false;
}
*/

/*
// 2-1. backtracking 방법 
vector<int> arrow(12);
// idx번째 값을 정함. 현재 회살은 left개 남아있음
void bt(int idx, int left) {
    if (idx == 10) {// 10번째의 값이 정해진 상황이라면
        arrow[idx] = left;
        //arrow를 가지고 점수 계산을 수행하면 됨
        return;
    }
    for (int i = 0; i <= left; i++) {
        arrow[idx] = i; // idx번째 화살의 수를 i개로 정함
        bt(idx+1, left - i); // 다음 단계로 들어감 
    }
}
*/

/*
// 2-2. next_permutation 방법 
vector<int> solution(int n, vector<int> info) {
    // 라이언이 가장 큰 점수 차이로 우승할 수 있는 결과를 저장
    // ret[0..10]
    // -> 10-i점에서 라이언이 맞힌 화살의 수, ret[11] : 점수 차이 
    vector<int> ret(12, -1);
    // 중복 조합을 위한 값(칸막이: 1)
    vector<int> brute(n + 10);
    // 10개의 칸막이를 배치 
    fill(brute.begin() + n, brute.end(), 1);
    do {
        // arrow[0..10]에 중복 조합의 결과 저장
        vector<int> arrow; // ret와 같은 형식
        int before = -1; 
        for (int i = 0; i < n + 10; i++) {
            if (brute[i]) {
                arrow.push_back(i - before - 1);
                 before = i;
            }
        }
        arrow.push_back(n + 10 - before - 1);
        int score = 0;
        for (int i = 0; i <= 10; i++) {
            if (arrow[i] > info[i]) 
                score += (10 - i);
            else if (info[i] != 0)
                score -= (10 - i);
        }

        if (score <= 0) continue;
        arrow.push_back(score);
        if (cmp(arrow, ret)) ret = arrow;
    } while(next_permutation(brute.begin(), brute.end()));

    if (ret[0] == -1) return vector<int>((-1)); // ryan이 이긴 경우가 하나도 없다. 
    ret.pop_back();
    return ret;
}
*/