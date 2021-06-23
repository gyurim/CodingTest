#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t>0){
        t--;
        int r;
        string input;
        char str[21];
       
        cin >> r;
        cin >> input;

        strcpy(str, input.c_str()); // 문자열 복사 
        // cstring 라이브러리 사용 

        for (int i = 0; i < input.length(); i++){
            for (int j = 0; j < r; j++){
                cout << str[i];
            }
        }
        cout << "\n";
    }
    return 0;
}
