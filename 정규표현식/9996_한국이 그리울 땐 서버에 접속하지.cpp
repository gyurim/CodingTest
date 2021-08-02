#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    int index = pattern.find("*");
    string first = pattern.substr(0, index);
    string end = pattern.substr(index+1, pattern.size()-1);

    // cout << first << " " << end << endl;

    // 첫 시작이 a이고 맨 끝이 b 
    // (first[A-Z]*end)

    // char to string 패턴 외우기 
    

    string p = first + "[a-z]*" + end;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (regex_match(str, regex(p))) cout << "DA\n";
        else cout << "NE\n";
    }

    return 0;
}