#include <algorithm>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    for (int i = 1; i <= count; i++) {
        answer += price * i;
    }
    
    // if (money <= answer) answer -= money;
    // else answer = 0;
    // return answer;

    return  max(0LL, answer - money); // LL은 long long을 의미
}