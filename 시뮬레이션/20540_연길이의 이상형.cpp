#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    string output;

    cin >> input;

    for (int i = 0; i < 4; i++) {
        if (input[i] == 'I') output += 'E';
        else if (input[i] == 'E') output += 'I';
        else if (input[i] == 'N') output += 'S';
        else if (input[i] == 'S') output += 'N';
        else if (input[i] == 'F') output += 'T';
        else if (input[i] == 'T') output += 'F';
        else if (input[i] == 'P') output += 'J';
        else if (input[i] == 'J') output += 'P';
    }

    cout << output;
    return 0;

}