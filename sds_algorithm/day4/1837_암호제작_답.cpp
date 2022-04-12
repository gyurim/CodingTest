#include <iostream>
using namespace std;

#define MAXS 102
#define MAXK 1000002

char P[MAXS]; // 두 소수의 곱 비밀키
int K; // K보다 작은 암호는 BAD, 큰 암호는 GOOD
bool Visit[MAXK]; // 소수: false, 소수 아님: true

// 초등학교 나눗셈 구현 
bool check(int n){
    int r = 0; // 나머지
    for (int i = 0; P[i]; i++){
        // 주어진 P를 각 자리수별로 (큰 자리수부터) 나누어 본다. 
        r = (r * 10 + (P[i] - '0')) % n;
    }

    return r == 0; // 나눠지면 true
}

// p는 3 * 5 = 15
// p는 143 = 11 * 13 

int main(){
    scanf("%s %d", P, &K);
    bool good = true;
    int minPrime = 0;

    // 에라토스테네스의 체 활용 
    for (int i = 2; i < K; i++) { // K보다 큰 소수는 계산할 필요가 없음
        if (Visit[i])
            continue;
        
        if (check(i)) { // i로 나뉘어 지는지 확인 
            good = false;
            minPrime = i;
            break;
        }

        // i*i는 int 범위를 넘어설 수 있음에 주의해야 한다.
        // 소수 아닌 애들 지움 
        for (long long j = (long long) i * i; j < K; j+= i) // 소수로 판별된 i의 제곱부터 보면 된다. 
            Visit[j] = true; // i*i의 배수는 소수가 아님
    }

    if (good) printf("GOOD\n");
    else printf("BAD %d\n", minPrime);

    return 0;
}