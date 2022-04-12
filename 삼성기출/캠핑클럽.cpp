#include <iostream>
#include <string.h>

using namespace std;
int maps[100005];

int findCampingIndex(int curIdx, int lastD, int firstD){
    for (int i = curIdx + lastD; i > curIdx + firstD; i--) {
        if (maps[i] == 3) {
            return i;
        }
    }
    return -1;
}

int findRestIndex(int curIdx, int lastD, int firstD) {
    for (int i = curIdx + lastD; i > curIdx + firstD; i--) {
        if (maps[i] == 2) {
            return i;
        }
    }
    return -1;
} 

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int lastDest;
        memset(maps, 0, sizeof(maps));

        for (int j = 0; j < n; j++) {
            cin >> maps[j];
            if (maps[j] == 3) lastDest = j;
        }

        int curIdx = 0;
        int time = 0;
        bool canTravel = true;

        while (curIdx < lastDest) {
            int campIdx = findCampingIndex(curIdx, 15, 6);
            // cout << "\ncurIdx: " << curIdx << endl;
            if (campIdx != -1) {
                // case 1) 6~15 거리에 캠핑장 O
                int restIdx = findRestIndex(curIdx, 6, 0);
                while (restIdx < campIdx) {
                    // cout << "rest: " << restIdx << endl;
                    if (restIdx != -1) {
                        // case 1-1) 1~6 거리에 휴게소 O -> 캠핑장과의 거리가 최대로 좁혀질 때까지 휴게소들에 방문한다. 
                        time += (restIdx-curIdx);
                        time++; // 휴게소 +1 
                        curIdx = restIdx;
                    } else {
                        // case 1-2) 1~6 거리에 휴게소 X 
                        
                        int midCampIdx = findCampingIndex(curIdx, 6, 0);
                        if (midCampIdx != -1) {
                            // case 1-2-1) 1~6 거리에 캠핑장 O
                            // cout << "midCampIdx: " << midCampIdx << endl;
                            time += (midCampIdx - curIdx);
                            curIdx = midCampIdx;
                            if (midCampIdx + 6 > campIdx) break;
                        } else {
                            // case 1-2-2) 1~6 거리에 캠핑장 X 
                            canTravel = false;
                            break;
                        }
                    }
                    if (restIdx + 6 > campIdx) break;
                    
                    restIdx = findRestIndex(curIdx, 6, 0);
                }
                if (canTravel) {
                    time += (campIdx - curIdx);
                    curIdx = campIdx;
                }
            } else {  
                // case 2) 6~15 거리에 캠핑장 X 
                int campIdx = findCampingIndex(curIdx, 6, 0);
                if (campIdx != -1) {
                    // case  2-1) 1~6 거리에 캠핑장 O 
                    time += (campIdx - curIdx);
                    curIdx = campIdx;
                } else {
                    // case 2-2) 1~6 거리에 캠핑장 X 
                    canTravel = false; 
                }
            }
            
            if (!canTravel) {
                time = -1;
                break;
            }
            if (curIdx == lastDest) break;
        }
        cout << "#" << i+1 << " ";
        time = -1;
        cout << time;
        if (i != t-1) cout << endl; 
    }
    return 0;
}