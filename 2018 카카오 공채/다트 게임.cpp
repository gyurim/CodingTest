#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;
// 더 깔끔한 풀이 
int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = {0, 0, 0}; // 3번의 점수 
    int options[3] = {1, 1, 1}; 

    for (int i = 0; i < 3; i++) {
        int score;
        char bonus, option;

        ss >> score;
        
        bonus = ss.get(); // get(): 커서를 앞(->)으로 한 칸 
        option = ss.get(); 

        if (option != '*' && option != '#')
            ss.unget(); // unget(): 커서를 뒤(<-)로 한 칸

        switch(bonus) {
            case 'S':
                sum[i] += score; 
                break;
            case 'D':
                sum[i] += pow(score, 2); // pow(): 제곱
                break;
            case 'T':
                sum[i] += pow(score, 3);
                break;
            default:
                break;
        }

        switch(option) {
            case '*':
                if (i > 0 && options[i-1]) options[i-1] *= 2;
                options[i] *= 2;
                break;
            case '#':
                options[i] = -options[i];
                break;
            default:
                break;
        }
    }
    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}

/*
// 내 풀이 
pair<int, int> findScore(string s){
    int idx = s.find("10");
    if (idx != string::npos) return {idx, 10};
    idx = s.find("0");
    if (idx != string::npos) return {idx, 0};
    idx = s.find("1");
    if (idx != string::npos) return {idx, 1};
    idx = s.find("2");
    if (idx != string::npos) return {idx, 2};
    idx = s.find("3");
    if (idx != string::npos) return {idx, 3};
    idx = s.find("4");
    if (idx != string::npos) return {idx, 4};
    idx = s.find("5");
    if (idx != string::npos) return {idx, 5};
    idx = s.find("6");
    if (idx != string::npos) return {idx, 6};
    idx = s.find("7");
    if (idx != string::npos) return {idx, 7};
    idx = s.find("8");
    if (idx != string::npos) return {idx, 8};
    idx = s.find("9");
    if (idx != string::npos) return {idx, 9};

    // if (idx = s.find("10") != string::npos)
    //     return {idx, 10}; 
    // 이렇게 하면 idx에는 bool 값이 담겨서, string::npos가 아닌 경우 항상 idx = 1 이 담김 
    return {string::npos, 0};
}

int solution(string dartResult) {
    int answer = 0;
    vector<int> vec;
    pair<int, int> result;

    while(true) {
        if (dartResult.length() == 0) break;
        result = findScore(dartResult.substr(0, 2)); // 파라미터로 dartResult 넣어주면 뒤에 나오는 점수 idx 리턴함;
        
        int s_idx = result.first;
        int b_idx = 0; // bonus idx
        int o_idx = 0; // option idx
        if (result.second == 10) {
            b_idx = s_idx + 2;
        } else {
            b_idx = s_idx + 1;
        }
        
        if (dartResult[b_idx] == 'S') {
            vec.push_back(result.second);
        } else if (dartResult[b_idx] == 'D') {
            vec.push_back(result.second * result.second);
        } else if (dartResult[b_idx] == 'T') {
            vec.push_back(result.second * result.second * result.second);
        }

        o_idx = b_idx + 1;
        if (dartResult[o_idx] == '#') {
            vec[vec.size()-1] = -vec[vec.size()-1];
        } else if (dartResult[o_idx] == '*') {
            if (vec.size() == 1) {
                vec[0] *= 2;
            } else {
                vec[vec.size()-1] *= 2;
                vec[vec.size()-2] *= 2;
            }
        } else {
            dartResult = dartResult.substr(o_idx);
            continue;
        }
        dartResult = dartResult.substr(o_idx + 1);
    }

    for (auto num : vec) {
        answer += num;
    }

    return answer;
}
*/
int main() {
    cout << solution("1D2S#10S");
    return 0;
}