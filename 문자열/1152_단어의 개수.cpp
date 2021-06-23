#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    string str;
    int count = 0;
    getline(cin, str);
    
    for (int i = 0; i < str.length(); i++){
        if (str[i] != ' ' && str[i+1] == ' ') count++;
        if (i == str.length()-1){
            if (str[i] != ' ') count++;
        }
        // 마지막 위치의 ' '는 \n와 같은 뜻으로 해석
    }

    cout << count;
    
    return 0;
}