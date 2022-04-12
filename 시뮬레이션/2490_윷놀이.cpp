#include <iostream>
using namespace std;

int main() {
    int zerocnt = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int a;
            cin >> a;
            if (a == 0) zerocnt++;
        }

        if (zerocnt == 0) cout << "E\n";
        else if (zerocnt == 1) cout << "A\n";
        else if (zerocnt == 2) cout << "B\n";
        else if (zerocnt == 3) cout << "C\n";
        else cout << "D\n";
        zerocnt = 0;
    }
    return 0;
}