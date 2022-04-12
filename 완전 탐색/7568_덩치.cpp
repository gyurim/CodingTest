#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> peoples[50] = {};

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        peoples[i] = make_pair(x, y);
    }

    for (int i = 0; i < n; i++) {
        int x = peoples[i].first;
        int y = peoples[i].second;
        int grade = 1;

        for (int j = 0; j < n; j++) {
            int p = peoples[j].first;
            int q = peoples[j].second;

            if (x < p && y < q) grade++;
        }
        cout << grade << " ";
    }

    return 0;
}