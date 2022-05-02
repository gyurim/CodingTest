// 2022.05.02 
// 통과 안됨 ㅠㅠ 

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<char> signs;

string typetwo(string s) {
    //type 2 
    char sign = '.';
    string word = "";
    for (auto c : s) {
        if (c >= 'A' && c <= 'Z') {
            word += c;
        } else if (c >= 'a' && c <= 'z') {
            if (sign == '.') {
                sign = c;
                if (signs.find(sign) != signs.end()) return "";
                else signs.insert(sign);
            } else {
                if (sign != c) {
                    return "";
                }
            }
        } else return "";
    }
    return word;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    vector<string> words;

    int i = 0;
    bool isInvalid = false;

    while (i < sentence.length()) {
        if (sentence[i] == ' ') {
            isInvalid = true;
            break;
        }

        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            // type 1
            string cpy_s = sentence.substr(i+1);
            int idx = cpy_s.find(sentence[i]);
            idx += i + 1;
            if (sentence[i+1] >= 'a' && sentence[i+1] <= 'z') {
                isInvalid = true;
                break;
            } 

            string exword = sentence.substr(i+1, idx - i - 1);
            string word = typetwo(exword);
            if (word == "") {
                isInvalid = true;
                break;
            } else {
                cout << word << endl;
                words.push_back(word);
                i = idx + 1;
            }
        } else if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
            if (sentence[i+1] >= 'A' && sentence[i+1] <= 'Z') {
                cout << sentence[i] << endl;
                words.push_back(to_string(sentence[i]));
                i++;
                continue;
            }

            char sign = sentence[i+1];
            if (signs.find(sign) != signs.end()) {
                isInvalid = true;
                break;
            } else signs.insert(sign);
            
            int j = i;
            string exword = "";
            while(true) {
                if (sentence[j] == sign) exword += sentence[j];
                else if (sentence[j] >= 'A' && sentence[j] <= 'Z') {
                    if (sentence[j+1] >= 'A' && sentence[j+1] <= 'Z') {
                        exword += sentence[j];
                        j++;
                        break;
                    }
                    exword += sentence[j];
                }
                else break;
                j++;
            }

            string word = typetwo(exword);
            if (word == "") {
                isInvalid = true;
                break;
            } else {
                cout << word << endl;
                words.push_back(word);
                i = j;
            }
        }
    }

    if (isInvalid) cout << "isInvalid";
    else {
        for (auto w : words) {
            cout << w << " ";
        }
    }

    return answer;
}

int main() {
    solution("AxAxAxAoBoBoB");
    return 0;
}