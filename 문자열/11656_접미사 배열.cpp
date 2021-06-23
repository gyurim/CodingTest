#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string str;
    getline(cin, str);

    vector <string> vector;
    
    int length = str.length();

    for (int i = 0; i < length; i++){
        string copyStr = str.substr(i, length);
        // substr 은 부분 문자열 만들어주는 함수 
        vector.push_back(copyStr);
    }

    sort(vector.begin(), vector.end());

    for (int i = 0; i < vector.size(); i++){
        cout << vector[i]<<'\n';
    }
    return 0;
}