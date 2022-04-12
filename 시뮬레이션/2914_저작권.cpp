#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // 평균값: 멜로디 개수 / 곡 개수 
    // 평균값은 올림
    // 적어도 몇 곡이 저작권이 있는 멜로디 ? 
    double a, i;
    cin >> a >> i;

    i = i - 1 + 0.01;
    cout << ceil(a*i);
    return 0;
}