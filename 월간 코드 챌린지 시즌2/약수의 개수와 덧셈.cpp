#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool isOdd(int num) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (num / i == i) cnt++; // 3 * 3 = 9 
            else cnt += 2; // 2 * 6 = 12 
        }
    }
    if (cnt % 2 == 0) return false;
    else return true;
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (isOdd(i)) answer -= i;
        else answer += i;
    }

    return answer;
}