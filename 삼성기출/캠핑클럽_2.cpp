#include <iostream>
using namespace std;
int maps[100005] = {-1};

int findCampIdx(int cur, int first, int end) {
    int curFirst = (cur - first > 0) ? cur - first : 0;

   for (int i = curFirst; i > cur; i--) {
        if (maps[i] == 3 || maps[i] == 0) return i;
    }
    return -1;
}

int findRestIdx(int cur, int first, int end) {
    int curFirst = (cur - first > 0) ? cur - first : 0;

    for (int i = curFirst; i > cur; i--) {
        if (maps[i] == 2 || maps[i] == 0) return i;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int totalTime = 0;
        int n;
        cin >> n;
        memset(maps, -1, sizeof(maps));
        int lastDestIdx = -1;

        for (int j = 0; j < n; j++) {
            cin >> maps[j];
            if (maps[j] == 3) lastDestIdx = j;
        }

        int curIdx = lastDestIdx;
        while (curIdx > 0) {
            int time = 0; 
            int campIdx = findCampIdx(curIdx, 15, 0);
            if (campIdx != -1) {
                // 캠핑장 존재 
                int ptr = campIdx; 
                while (ptr < curIdx) {
                    ptr = 
                }
            }
            int ptr = campIdx;

            while (ptr)

        }





        cout << "#" << i << " " << time << endl;
    }
}