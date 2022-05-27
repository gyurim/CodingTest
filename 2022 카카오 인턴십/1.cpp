#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n = survey.size();
    map<char, int> mbti;
    mbti.insert({'R', 0});
    mbti.insert({'T', 0});
    mbti.insert({'C', 0});
    mbti.insert({'F', 0});
    mbti.insert({'J', 0});
    mbti.insert({'M', 0});
    mbti.insert({'A', 0});
    mbti.insert({'N', 0});

    for (int i = 0; i < n; i++) {
        int a = survey[i][0];
        int b = survey[i][1];

        if (choices[i] == 1) { // 매우 비동의 
            auto it = mbti.find(a);
            it->second += 3;
        } else if (choices[i] == 2) {
            auto it = mbti.find(a);
            it->second += 2;
        } else if (choices[i] == 3) {
            auto it = mbti.find(a);
            it->second += 1;
        } else if (choices[i] == 5) {
            auto it = mbti.find(b);
            it->second += 1;
        } else if (choices[i] == 6) {
            auto it = mbti.find(b);
            it->second += 2;
        } else if (choices[i] == 7) {
            auto it = mbti.find(b);
            it->second += 3;
        }
    }

    string arr[] = {"RT", "CF", "JM", "AN"};
    for (int i = 0; i < 4; i++) {
        auto a_it = mbti.find(arr[i][0]);
        auto b_it = mbti.find(arr[i][1]);

        if (a_it->second >= b_it->second) {
            answer += a_it->first;
        } else if (a_it->second < b_it->second) {
            answer += b_it->first;
        } 
    }

    return answer;
}