#include <string>
#include <vector>
#include <iostream>

using namespace std;

char setScore(double average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 50) return 'D';
    return 'F';
}

string solution(vector<vector<int>> scores) {
    string answer = "";

    int arr[12] = {0};
    int n = scores.size();
    int n_arr[12] = {0};

    for (int i = 0; i < n; i++) {
        int max_num = 0;
        int min_num = 100;

        for (int j = 0; j < n; j++) 
            arr[j] += scores[i][j];
        
        for (int j = 0; j < n; j++) {
            // 남이 매긴 점수들 중에서 max, min 점수를 구한다. 
            if (i == j) continue;
            max_num = max(max_num, scores[j][i]); // 문제 제대로 읽기! 
            min_num = min(min_num, scores[j][i]);
        }
        
        if (max_num < scores[i][i] || min_num > scores[i][i]) {
            arr[i] -= scores[i][i];
            n_arr[i] = n - 1;
        } else n_arr[i] = n;
    }

    for (int i = 0; i < n; i++) {
        answer += setScore((double)arr[i] / (double)n_arr[i]);
    }
    return answer;
}