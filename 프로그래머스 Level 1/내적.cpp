#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    // int answer = 1234567890;
    int answer = 0;

    for(int i = 0; i < a.size(); i++){
        int sum = a[i] * b[i];
        answer += sum;
    }

    return answer;
}

