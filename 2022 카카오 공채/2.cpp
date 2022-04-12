#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    //에라토스테네스의 체를 사용하면 시간초과 + 런타임 에러 

    // n을 k진수로 바꾸기 
    int nn = n;
    string s = "";

    while(nn >= k) {
        s = to_string(nn % k) + s;
        nn /= k;
    }
    s = to_string(nn) + s;
    
    // s 안에서 소수가 몇 개인지 
    while (true) {
        if (s.find('0') != string::npos) {
            int idx = s.find('0');
            string str_num = s.substr(0, idx);
            s = s.substr(idx + 1, s.length() - idx - 1);

            long long num = atoll(str_num.c_str());
            if (isPrime(num)) {
                answer++;
            }
        } else {
            if (s.length() == 0) break;
            long long num = atoll(s.c_str());
            
            if (isPrime(num)) {
               answer++;
            }
            break;
        }
    }
    return answer;
}