#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        string str;
        cin >> str;

        if (regex_match(str, regex("(100+1+|01)+")))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}