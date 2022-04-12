#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool canvas[101][101] = {false};

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        for (int i = a; i < a + 10; i++) {
            for (int j = b; j < b + 10; j++) {
                canvas[i][j] = {true};
            }
        }
    }

    int area = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (canvas[i][j] == true) area++;
        }
    }
    cout << area;
    return 0;
}