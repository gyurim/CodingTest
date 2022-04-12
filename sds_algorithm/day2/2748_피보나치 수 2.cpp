#include <iostream>
using namespace std;

int sequence[91] = {};

long long fib(int n){
    sequence[0] = 0;
    sequence[1] = 1;

    if (n <= 1) return sequence[n];
    else sequence[n] = fib(n-1) + fib(n-2);

    return sequence[n];
}

int main() {
    int n;
    cin >> n;

    long long num = fib(n);
    cout << num;
    return 0;
}