#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = 0;

    if (n >= 5) {
        answer += n / 5 - 1;
        n -= (n / 5 - 1) * 5;
    }

    if (n > 5) {
        if (n % 2 == 1) {
            answer++;
            n -= 5;
            answer += (n / 2);
        } else answer += (n / 2);
    }
    else if (n == 5) answer++;
    else {
        if (n % 2 == 1) answer = -1;
        else answer += (n / 2);
    }
    cout << answer;
    return 0;
}