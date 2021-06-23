#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    while (getline(cin, s))
    {
        int blankCount = 0;
        int smallCount = 0;
        int bigCount = 0;
        int numberCount = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                blankCount++;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                smallCount++;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                bigCount++;
            } else if (s[i] >= '0' && s[i] <= '9')
                numberCount++;
        }
        cout << smallCount << bigCount << numberCount << blankCount << "\n";
    }
    return 0;
}