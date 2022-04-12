#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string p;
int k;

bool check(int n) {
    int r = 0;
    for (int i = 0; i < p.length(); i++) {
        r = ((r * 10) + (p[i] - '0')) % n;
    }
    if (r == 0) return true; // p / n == 0
    return false; // p / n != 0
}

int main(){
    cin >> p >> k;
    // 시간 너무 많이 걸림 ㅠㅠ 

    // vector + fill_n 사용할땐 벡터 초기화 및 *메모리 할당* 해주고 !! 
    vector<bool> primes(k+1); 
    // 벡터 이름만 적지말고 .begin() 붙여서 제대로 가리키도록 하기 ㅠㅠ 
    fill_n(primes.begin(), k+1, true);
    
    primes[1] = false;
    bool isGood = true;
    int ans = 0;
    
    for (int i = 2; i < k; i++) {
        if (primes[i]) {

            if (check(i)) {
                isGood = false;
                ans = i;
                break;
            }
            // 소수가 아니면 지움 
            for (int j = 2; j * i < k; j++) {
                if (!primes[i*j]) continue;
                primes[i*j] = false;
            }
        }
    }

    if (isGood) cout << "GOOD";
    else cout << "BAD " << ans;

    return 0;   
}