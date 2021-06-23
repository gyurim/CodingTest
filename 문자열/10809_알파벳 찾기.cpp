#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int output[101];
    // for문보다 빠른 배열 초기화 
    memset(output, -1, sizeof(output));
    char inputArr[101];
    string input;

    cin >> input;
    strcpy(inputArr, input.c_str());
    
    for (int i = 0; i < input.length(); i++){
        // 소문자 a의 ascii = 97
        int currentAscii = (int)inputArr[i] - 97;
        if(output[currentAscii] == -1){
            output[currentAscii] = i;
        }
    }

    // 알파벳 개수는 26
    for (int i = 0; i < 26; i++){
        cout<<output[i]<<" ";
    }

    return 0;
}