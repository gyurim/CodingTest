#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

// 방법 1 
// 실행 안됨. 

bool is_valid_place(const vector<string>& place) {
    constexpr int N = 5;

    vector<vector<int>> is_in_use(N, vector<int>(N, false));

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (place[i][j] == 'P') {
                for(int k = 0; k < 4; k++) {
                    int moved_i = i + di[k];
                    int moved_j = j + dj[k];

                    if (moved_i >= N || moved_j >= N) continue;
                    
                    switch(place[moved_i][moved_j]) {
                        case 'P': return false;
                        case 'O': 
                            if (is_in_use[moved_i][moved_j]) return false;
                            is_in_use[moved_i][moved_j] = true;
                            break;
                        case 'X': break;
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);
    for (int i = 0; i < 5; i++) {
        answer.push_back(is_valid_place(places[i]));
    }

    return answer;
}

// 방법 2

// vector<int> solution(vector<vector<string>> places) {
//     vector<int> answer;

//     for (int i = 0; i < places.size(); i++) {
//         vector<pair<int, int>> people_seat;

//         for (int j = 0; j < places[i].size(); j++) {
//             string row = places[i][j];

//             for (int k = 0; k < row.length(); k++) {
//                 char seat = row[k];

//                 if (seat == 'P') {
//                     people_seat.push_back(make_pair(j, k));
//                 }
//             }
//         }
        
//         int flag = 1;

//         for (int j = 0; j < people_seat.size(); j++) {
//             for (int k = j + 1; k < people_seat.size(); k++) {
//                 int distance = abs(people_seat[j].first - people_seat[k].first) + abs(people_seat[j].second - people_seat[k].second);
            
//                 if (distance > 2) {
//                     continue;
//                 } else if (distance == 2) {
//                     int x = (people_seat[j].first + people_seat[k].first)/2;
//                     int y = (people_seat[j].second + people_seat[k].second)/2;

//                     string row = places[i][x];

//                     if (abs(people_seat[k].first - people_seat[j].first) == 1) {
//                         if (places[i][people_seat[k].first][people_seat[j].second] == 'O') {
//                             flag = 0;
//                             break;
//                         } 
//                         if (places[i][people_seat[j].first][people_seat[k].second] == 'O') {
//                             flag = 0;
//                             break;
//                         }
//                     } else {
//                     // 조건 확인 
//                         if (row[y] == 'O') {     
//                             flag = 0;
//                             break;
//                         }
//                     }
                    
//                 } else {
//                     flag = 0;
//                     break;
//                 }
//             }
//             if (flag == 0) break;
//         }
//         answer.push_back(flag);
//     }
//     return answer;
// }
