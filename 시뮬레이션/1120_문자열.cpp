#include <iostream> 
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;

    int min = 51;
    // ad bacd 
    // a가 b에 가장 많이 중첩됐을 때를 구함 
    for (int i = 0; i <= b.length() - a.length(); i++) {
        int cnt = 0;

        for (int j = 0; j < a.length(); j++) {
            if (a[j] != b[i+j]) cnt++;
        }

        min = (min > cnt) ? cnt : min;
    }
    cout << min;
    
    return 0;
}