#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 1. 구간 합으로 다시 풀어보기 
// 2. 내가 푼 풀이가 '최소 횟수가 증명이 되는 지 확인하기 
int solution(vector<int> queue1, vector<int> queue2) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = queue1.size();
    long long answer = 0;
    long long sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }

    int idx1 = 0;
    int idx2 = 0;

    while(1) {
        // queue는 선입선출. 따라서 순서 O. insert가 2바퀴 이루어지면 원래 상태로 돌아온다. 
        // * 2 해줘도 됐을거 같은데 넉넉잡아서 * 4로 함
        if (answer > n * 4) { 
            answer = -1;
            break;
        }

        if (sum1 > sum2) {
            // queue1 에서 원소 pop 
            queue2.push_back(queue1[idx1]);
            sum1 -= queue1[idx1];
            sum2 += queue1[idx1];
            idx1++;
        } else if (sum1 < sum2) {
            // queue2 에서 원소 pop
            queue1.push_back(queue2[idx2]);
            sum2 -= queue2[idx2];
            sum1 += queue2[idx2];
            idx2++;
        } else if (sum1 == sum2) break;
        answer++;
    }
    
    return answer;
}
