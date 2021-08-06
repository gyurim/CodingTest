#include <iostream>
#include<cmath> // sqrt

using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    ll r = sqrt(n);

    r = (r*r == n) ? r : r+1;
    cout << r;
    return 0;
}

// 왜 틀렸지 ㅠㅠ 그냥 sqrt 쓰자 ! 
// int main() {
//     long long n;
//     cin >> n;

//     long long low = 1;
//     long long high = n / 2;
//     long long mid = 0;

//     while (low <= high) {
//         mid = (low + high) / 2;

//         long long result = mid * mid;

//         if (result < n) low = mid + 1;
//         // reslult <= 0 은 오버플로우가 발생했을 시 처리 
//         else if (result > n || result <= 0) high = mid - 1;
//         else break;
//     }
    
//     if (mid * mid < n) mid++;

//     cout << mid;
//     return 0;
// }