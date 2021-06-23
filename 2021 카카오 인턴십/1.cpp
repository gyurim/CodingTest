#include <string>
#include <vector>

using namespace std;

string tmp = ""; // 변수로 넘길 수 있도록 수정하기 

int stringToInt(){
    if (tmp == "zero") return 0;
    else if (tmp == "one") return 1;
    else if (tmp == "two") return 2;
    else if (tmp == "three") return 3;
    else if (tmp == "four") return 4;
    else if (tmp == "five") return 5;
    else if (tmp == "six") return 6;
    else if (tmp == "seven") return 7;
    else if (tmp == "eight") return 8;
    else if (tmp == "nine") return 9;
    else return 10;
 }

int solution(string s) {
    int answer = 0;

    string result;
  
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 48 && s[i] <= 57){
            result += s[i];
        } else {
            tmp += s[i];
            int _tmp = stringToInt();
            
            if (_tmp != 10){
                tmp = "";
                result += to_string(_tmp);
            }
        }
    }

    answer = stoi(result);
    

    return answer;
}