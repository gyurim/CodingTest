#include <iostream>
#include <map>
using namespace std;

map<string, int> trees;
// map<string, double>::iterator it;

int main() {
    string tree;
    double total = 0;
    while(getline(cin, tree)) {
        total++;
        bool isFind = false;
        auto it = trees.find(tree);
        if (it == trees.end()) {
            trees.insert({tree, 1});
        } else {
            it->second++;
        }
    }

    for (auto it : trees) {
        cout << fixed; // 소수점 아래 
        cout.precision(4); // 4번째 자리까지 출력 
        cout << it.first << " " << it.second  * 100 / total << endl;
    }
    return 0;
}