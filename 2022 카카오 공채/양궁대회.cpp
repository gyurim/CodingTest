// 2022.04.20

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int _n;
vector<int> apeach;
vector<int> answer;
vector<int> ryan(11, 0); // 초기화 
int max_ryan = 0;

void func(int k, int idx) {
    if (k == _n) {
        // 차이 계산 
        int sum_ryan = 0;
        int sum_apeach = 0;
        for (int i = 0; i <= 10; i++) {
            if (ryan[i] > apeach[i])
                sum_ryan += 10 - i;
            else {
                if (apeach[i] == 0) continue;
                sum_apeach += 10 - i;
            }
        }
        int diff = sum_ryan - sum_apeach;
        
        if (diff > 0 && max_ryan <= diff) {
            // 가장 큰 점수 차이로 우승할 수 있는 방법이 여러 가지 일 경우, 가장 낮은 점수를 더 많이 맞힌 경우를 리턴 
            if (max_ryan == diff) { 
                vector<vector<int>> low;
                reverse(answer.begin(), answer.end());
                reverse(ryan.begin(), ryan.end());
                low.push_back(answer);
                low.push_back(ryan);
                sort(low.begin(), low.end());
                reverse(low[1].begin(), low[1].end());
                answer = low[1];
                reverse(ryan.begin(), ryan.end()); // 다시 원상복귀 .. ㅠㅠ 이거 안해서 시간 오래걸림 
            } else {
                answer = ryan;
                max_ryan = diff;
            }
        }
        return;
    }
    
    for (int i = idx; i <= 10; i++) {
        if (k + apeach[i] + 1 <= _n) {
            ryan[i] = apeach[i] + 1;
            func(k + ryan[i], i + 1);
            ryan[i] = 0;
        } else {
            ryan[i] = _n - k;
            func(k + ryan[i], i + 1);
            ryan[i] = 0;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    _n = n;
    apeach = info;
    func(0, 0);
    if (max_ryan == 0) answer = {-1};
    return answer;
}

int main() {
    vector<int> info {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1};
    int n = 9;
    solution(n, info);
    return 0;
}