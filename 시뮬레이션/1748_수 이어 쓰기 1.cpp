#include <iostream>
using namespace std;

long long arr[12];

void makearr() {
    string s = "";
    for (int i = 0; i < 8; i++) {
        s += "9";
        arr[i] = stoi(s);
    }
}

int main() {
    makearr();
    string n;
    cin >> n;
    long long num = stoi(n);
    long long result = num;

    for (int i = 1; i < n.length(); i++) {
        result += (num - arr[i]);
    }
    cout << result;
    return 0;
}