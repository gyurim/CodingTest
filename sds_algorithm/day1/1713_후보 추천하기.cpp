#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> pictures;
int voteCnt[101] = {0};

int main() {
    int n, total;
    cin >> n >> total;

    int vote;
    
    for (int i = 0; i < total; i++) {
        cin >> vote;
        voteCnt[vote]++;

        // 사진틀에 존재하는지 유무 파악
        bool isExisted = false;
        for (int j = 0; j < pictures.size(); j++) {
            if (pictures[j].first == vote) {
                isExisted = true;
                break;
            }
        }

        if (!isExisted) {
            if (pictures.size() < n) {
                pictures.push_back({vote, i});
            } else {
                // 비어있는 사진틀 없는 경우 -> 교체 필요 
                int min = voteCnt[pictures[0].first];
                
                for (int j = 1; j < pictures.size(); j++) {
                    min = (min > voteCnt[pictures[j].first]) ? voteCnt[pictures[j].first] : min;
                }

                vector<int> minVote;
                int minPicturesNum = 0;
                int oldVote = 1001;
                int oldPicturesNum = 0;

                for (int j = 0; j < pictures.size(); j++) {
                    if (min == voteCnt[pictures[j].first]) {
                        minVote.push_back(pictures[j].first);
                        minPicturesNum = j;

                        if (oldVote > pictures[j].second) {
                            oldVote = pictures[j].second;
                            oldPicturesNum = j;
                        }
                    }
                }

                if (minVote.size() == 1) {
                    voteCnt[minVote[0]] = 0;
                    pictures[minPicturesNum] = {vote, i};
                } else if (minVote.size() > 1) {
                    // 가장 오래된 사진 삭제 
                    voteCnt[pictures[oldPicturesNum].first] = 0;
                    pictures[oldPicturesNum] = {vote, i};
                }
            }
        }
    }
    // 정렬 하기 ~ 

    sort(pictures.begin(), pictures.end());
    for (int i = 0; i < pictures.size(); i++) {
        cout << pictures[i].first << " ";
    }
    return 0;
}