#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    int n = line.size();

    vector<bool> flag;
    for (int i = 0; i < n; i++) {
        if (i < 2) flag.push_back(0);
        else flag.push_back(1);
    }

    do {
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (flag[i] == 0) {
                idx.push_back(i);
            }
        }

        // 교점 구하기 
        int a1 = line[idx[0]][0], b1 = line[idx[0]][1], c1 = line[idx[0]][2];
        int a2 = line[idx[1]][0], b2 = line[idx[1]][1], c2 = line[idx[1]][2];

        


    } while (next_permutation(flag.begin(), flag.end()));

    return answer;
}