#include <iostream>
#include <vector>

using namespace std;

vector<int> divisor(int n) {
    vector<int> div;
    for (int i = 1; i*i <= n; i++) {
        if (n % i = 0) div.push_back(i);
    }

    // (int)div.size() 형변환시켜준 이유:
    // div.size()는 unsigned를 반환함. 
    // 만약 (int)가 없다면 32bit 컴퓨터 기준으로 div.size()-1 = -1이 아니라 
    // unsigned int로 되어 2^32-1를 가지게 된다. 따라서 n = 0일때, int overflow 발생 
    for (int j = (int)div.size() - 1; j >= 0; j--) {
        if (div[j] * div[j] == n) continue;
        div.push_back(n / div[j]);
    }
    return div;
}