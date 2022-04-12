#include <iostream>
using namespace std;

int main() {
    char matrix[10][10];
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> matrix[i][j];

            if ((i + j) % 2 == 0) {
                if (matrix[i][j] == 'F') cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}