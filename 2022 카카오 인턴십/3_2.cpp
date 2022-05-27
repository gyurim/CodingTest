#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// #define MAX 1000000 // 초기화를 잘 하자;; 987654321 했는데 안됐음.. 
#define MAX 987654321

int GA, GB;
int dy[200][200];

void renew(int nextA, int nextB, int newValue) {
    // dy[nextA][nextB]를 newValue로 갱신시켜라 
    nextA = min(nextA, GA);
    nextB = min(nextB, GB);
    dy[nextA][nextB] = min(dy[nextA][nextB], newValue);
}


int solution(int alp, int cop, vector<vector<int>> problems) {
    
    memset(dy, MAX, sizeof(dy));
    dy[alp][cop] = 0;

    int ans = MAX;

    for (auto problem : problems) {
        GA = max(GA, problem[0]);
        GB = max(GB, problem[1]);
    }

    for (int a = alp; a < GA + 1; a++) {
        for (int b = cop; b < GB + 1; b++) {
            // 현재 능력치: a, b

            // 도달할 수 없는 불가능한 상황 
            if (dy[a][b] == MAX)
                continue; 

            // dy[A][B] 값 계산 
            // (1) 모든 새로운 값을 다 계산하는 방법
            // // 1. 마지막에 1번 작업을 하는 경우 
            // dy[a][b] = min(dy[a][b], dy[a-1][b] + 1);
            // // 2. 마지막에 2번 작업을 하는 경우
            // dy[a][b] = min(dy[a][b], dy[a][b-1] + 1);
            // // 3. 마지막에 아이템을 썼을 때
            // for (auto problem : problems) {
            //     int ca = problem[2]; // alp reward
            //     int cb = problem[3]; // cop reward
            //     int prevA = a - ca;
            //     int prevB = b - cb;

            //     if (prevA < problem[0] || prevB < problem[1]) {
            //         // 마지막에 이 아이템을 썼을 리가 없다.
            //         continue;
            //     }
            //     if (dy[prevA][prevB] == MAX) {
            //         // A가 prevA 이고, B가 prevB 인 상황까지 도달하는 게 불가능하다.
            //         continue;
            //     }

            //     dy[a][b] = min(dy[a][b], dy[prevA][prevB] + problem[4]);
            // }

            // (2) 알고 있던 값으로 새로운 값을 계산해주는 방법 -> 더 나은 방법 
            // 시간 복잡도는 똑같음. 
            // 그러나 장점 : 다음 순간에 a와 b가 굳이 150을 넘어갈 필요가 없다는 것을 알게 된다. 
            // 그래서 예시로 dy[a+1][b]에서 a+1이 150을 넘어간다면, (혹은 목표 알고력, 코딩력) 기록해줄 필요가 없게 된다. 

            // dy[a][b] 값을 알고 있다 == 시작 상황에서 a, b까지 필요한 최소 시간을 안다. 
            // 1. 이 순간에 1번 작업을 했을 때
            renew(a+1, b, dy[a][b] + 1);
            // 2. 이 순간에 2번 작업을 했을 때
            renew(a, b+1, dy[a][b] + 1);

            // 3. 이 순간에 아이템을 썼을 때
            for (auto problem : problems) {
                int ca = problem[2];
                int cb = problem[3];

                if (a < problem[0] || b < problem[1])
                    continue;

                int nextA = a + ca;
                int nextB = b + cb;
            
                renew(nextA, nextB, dy[a][b] + problem[4]);
            }
            
        }
    }

    for (int i = alp; i <= GA; i++) {
        for (int j = cop; j <= GB; j++) {
            cout << "dy[" << i << "]["<<j <<"] = " << dy[i][j] << endl;
        }
    }

    ans = dy[GA][GB];
    cout << ans << endl;
    return ans;
}

int main(){
    string s = "[[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]";
    vector<vector<int>> build_frame;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            int j = i + 1;
            vector<int> vec;
            string number = "";
            while(s[j] != ']') {
                if (s[j] >= '0' && s[j] <= '9') {
                    number += s[j];
                } else if (s[j] == ',') {
                    vec.push_back(atoi(number.c_str()));
                    number = "";
                }
                j++;
            }
            vec.push_back(atoi(number.c_str()));
            number = "";
            i = j;
            build_frame.push_back(vec);
        }
    }
    
    cout << solution(0, 0, build_frame);
    return 0;
}
