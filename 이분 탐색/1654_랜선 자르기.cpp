// 다시 풀어보기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;
long long k, n;

bool divide(long long key) {
    int count = 0;

    for (int i = 0; i < v.size(); i++) 
        count += v[i] / key;

    return count >= n ? true : false;
}

int main() {
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        long long lan;
        cin >> lan;
        v.push_back(lan);
    }

    sort(v.begin(), v.end());

    long long key = 0;
    long long low = 1;
    long long high = v[v.size()-1];
    long long result = 0;

    while(low <= high){ 
        key = (low + high) / 2;

        if (divide(key)) {
            if (result < key) {
                result = key; // 조건을 만족하는 수 중에서도 최대값을 찾기 위함 
            } 
            low = key + 1;
        } else {
            high = key - 1;
        }
    }
    cout << result;
    return 0; 
}