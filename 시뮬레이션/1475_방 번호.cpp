#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (n / 10 > 0) {
        int rest = n % 10;
        arr[rest]++;
        n = n / 10;
    }
    arr[n]++;

    int max_num = -1;
    int max = -1;

    for (int i = 0; i < 10; i++) {
        max = (max <= arr[i]) ? arr[i] : max;
        max_num = i;
    }

    if (max_num == 6 || max_num == 9) {
        max = ((arr[6] + arr[9]) % 2 > 0) ? (arr[6] + arr[9]) / 2 + 1 : (arr[6] + arr[9]) / 2;
        
        for (int i = 0; i < 10; i++) {
            if (i == 6 || i == 9) continue;
            max = (max <= arr[i]) ? arr[i] : max;
            max_num = i;
        }
    }
    cout << max;
    return 0;
}