#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int checkKeepDistance(vector<string> room, vector<pair<int, int>> pIdx) {
    vector<int> isCompare;
    int answer = 1;

    if (pIdx.size() < 2) return 1; // 이걸 안 해주면 do while문을 무조건 돌기 때문에 예상과 다른 결과 출력될 수 있음 (오류잡느라 시간 걸림;)

    for (int i = 0; i < pIdx.size(); i++) {
        if (i < 2) isCompare.push_back(0);
        else isCompare.push_back(1);
    }

    do {
        bool isFirst = false;
        int x1, x2, y1, y2 = 0;

        for (int i = 0; i < isCompare.size(); i++) {
            if (isCompare[i] == 0) {
                // 비교 대상
                if (!isFirst) {
                    isFirst = true;
                    x1 = pIdx[i].first;
                    y1 = pIdx[i].second;
                } else {
                    x2 = pIdx[i].first;
                    y2 = pIdx[i].second;
                }
            }
        }
        int dist = abs(x1 - x2) + abs(y1 - y2);

        if (dist < 2) answer = 0;
        else if (dist == 2) {
            if (x1 == x2) { 
                int y = (y1 + y2) / 2;
                if (room[x1][y] != 'X') answer = 0;
                // cout << x1 << ", " << y << endl;
            } else if (y1 == y2) {
                int x = (x1 + x2) / 2;
                if (room[x][y1] != 'X') answer = 0;
                // cout << x << ", " << y1 << endl;
            } else {
                if (room[x1][y2] != 'X' || room[x2][y1] != 'X') answer = 0;
                // cout << x1 << ", " << y2 << " & " << x2 << " ," << y1 << endl;
            }
        }

        if (answer == 0) break; 
    } while (next_permutation(isCompare.begin(), isCompare.end()));

    return answer;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; i++) {
        vector<pair<int, int>> pIdx;
        vector<string> room = places[i];

        for (int j = 0; j < 5; j++) {
            string s = room[j];

            for (int k = 0; k < 5; k++) {            
                if (s[k] == 'P') {
                    pIdx.push_back(make_pair(j, k));
                }
            } 
        }
        cout << endl;
        answer.push_back(checkKeepDistance(room, pIdx));
    }
    return answer;
}