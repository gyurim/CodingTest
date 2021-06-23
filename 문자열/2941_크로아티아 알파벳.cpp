#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    string input;
    char inputArr[101];
    cin >> input;

    strcpy(inputArr, input.c_str()); // #include <cstring> 

    int count = 0;
    for (int i = 0; i < input.length(); i++){
        count++;

        char current = inputArr[i];
        if (current == '='){
            if (inputArr[i-1] == 'c' || inputArr[i-1] == 's'){
                count--;
            } else if (inputArr[i-1] == 'z'){
                if (inputArr[i-2] == 'd')
                    count -= 2;
                else 
                    count--;
            }
        }

        if (current == '-'){
            if (inputArr[i-1] == 'c' || inputArr[i-1] == 'd'){
                count--;
            } 
        }

        if (current == 'j'){
            if (inputArr[i-1] == 'l' || inputArr[i-1] == 'n') {
                count--;
            }
        }
    }

    cout << count;
    

    return 0;
}