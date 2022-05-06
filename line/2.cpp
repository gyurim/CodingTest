// 테케 틀렸음;; 

// #include <string>
// #include <vector>
// #include <iostream>
// #include <map>
// #include <algorithm>

// using namespace std;

// bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
//     return a.second < b.second;
// }

// int solution(vector<string> sentences, int n) {
//     int answer = 0;
//     int shiftCnt[30];
//     memset(shiftCnt, 0, sizeof(shiftCnt)); 
//     map<char, int> alpha;
    
//     for (auto s : sentences) {
//         for (auto c : s) {
//             if (c == ' ') continue;

//             if (c >= 'A' && c <= 'Z') {
//                 shiftCnt[c - 'A']++;
//                 c |= 32;

//                 auto it = alpha.find(' ');
//                 if (it == alpha.end())
//                     alpha.insert({' ', 1});
//                 else it->second++;
//             }
            
//             auto idx = alpha.find(c);
//             if (idx == alpha.end()) {
//                 alpha.insert({c, 1}); 
//             }
//             else {
//                 idx->second++;
//             }
//         }
//     }
//     vector<pair<char, int>> vec;
//     for (auto& it : alpha) 
//         vec.push_back(it);
        
//     sort(vec.begin(), vec.end(), cmp);

//     bool isShift = false;
//     for (int i = 1; i <= n-1; i++) {
//         if (vec[vec.size() - i].first == ' ') {
//             isShift = true;
//         }
//     }

//     if (isShift) {
//         for (int i = 1; i <= n-1; i++) 
//             answer += vec[vec.size() - i].second;
//     } else {
//         for (int i = 1; i <= n; i++)
//             answer += vec[vec.size() - i].second;
//     }
    
//     return answer;
// }

// int main() {
//     // vector<string> sentences {"line in line", "LINE", "in lion"};
//     vector<string> se {"ABcD", "bdbc", "a", "Line neWs"};
//     cout << solution(se, 7);
//     return 0;
// }