#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<vector<int>> scores){
    // 만약 자기 자신을 평가한 점수가 유일한 최고점, 유일한 최저점인 경우 해당 점수를 제외하고 평균 

    int n = scores.size();
    vector<double> grades;
    
    for (int i = 0; i < n; i++) {
        double score = 0;
        map<int, int, greater<int>> cnt; // 내림차순 
        for (int j = 0; j < n; j++) {
            auto it = cnt.find(scores[j][i]);
            if (it == cnt.end()) {
                cnt.insert({scores[j][i], 1});
            } else {
                it->second++;
            }
            score += scores[j][i];
        }
        
        auto bigger_it = cnt.begin();
        if (bigger_it->first == scores[i][i]) {
            if (bigger_it->second == 1) {
                score -= scores[i][i];
                score /= (n-1);
                grades.push_back(score);
            } else {
                score /= n;
                grades.push_back(score);
            }
            continue;
        } 
        
        auto smaller_it = cnt.end();
        smaller_it--;
        if (smaller_it->first == scores[i][i]) {
            if (smaller_it->second == 1) {
                score -= scores[i][i];
                score /= (n-1);
                grades.push_back(score);
            } else {
                score /= n;
                grades.push_back(score);
            }
            continue;
        }
        score /= n;
        grades.push_back(score);
    }
    
    string ans = "";
    for (auto grade : grades) {
        // cout << grade << endl;
        if (grade >= 90) {
            ans += 'A';
        } else if (grade >= 80) {
            ans += 'B';
        } else if (grade >= 70) {
            ans += 'C';
        } else if (grade >= 50) {
            ans += 'D';
        } else ans += 'F';
    }
    
    cout << ans;
    return ans;
}

int main() {
    // vector<vector<int>> scores {{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}};
    // FABABD
    // vector<vector<int>> scores {{50, 90}, {50, 87}}; // DA
    vector<vector<int>> scores{{70, 49, 90}, {68, 50, 38}, {73,31, 100}};
    solution(scores);
    return 0;
}
