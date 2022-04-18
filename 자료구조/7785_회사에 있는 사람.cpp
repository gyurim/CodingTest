// 2022.04.18

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    string cmd;
    string name, state;
    set<string> company;
    cin.ignore(); // getline 에러 뜨면 써주기 

    while (n--) {
        getline(cin, cmd);

        istringstream iss(cmd);
        iss >> name >> state;

        if (state == "enter") {
            company.insert(name);
        } else {
            company.erase(name);
        }
    }

    // set 역순 정렬 
    set<string>::reverse_iterator it;
    for (it = company.rbegin(); it != company.rend(); it++)
        cout << *it << '\n';

    return 0;
}