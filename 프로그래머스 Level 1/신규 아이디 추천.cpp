#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.length(); i++){
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = new_id[i] - 'A' + 'a' ; // 대문자 -> 소문자 변환 
    }

    for (int i = 0; i < new_id.length(); i++){
        if (!((new_id[i] >= 'a' && new_id[i] <= 'z') || new_id[i] == '.' || new_id[i] == '_' || new_id[i] == '-' || (new_id[i] >= '0' && new_id[i] <= '9'))){
            new_id.erase(i, 1); // i번째 문자부터 1개 삭제 
            i -= 1;
        }
    }

    for (int i = 0; i < new_id.length(); i++){
        if (i > 0 && new_id[i] == '.' && new_id[i] == new_id[i-1]){
            new_id.erase(i, 1);
            i -= 1;
        }
    }

    if (new_id[0] == '.') {
        new_id.erase(0, 1);
    }

    if (new_id[new_id.length()-1] == '.'){
        new_id.erase(new_id.length()-1, 1);
    }

    if (new_id == "") new_id = "a";

    if (new_id.length() >= 16)
        new_id.erase(15, new_id.length() - 15);

    if (new_id[new_id.length()-1] == '.'){
        new_id.erase(new_id.length()-1, 1);
    }

    int length = new_id.length();

    if (length <= 2) {
        for (int i = 0; i < 3 - length; i++){
            new_id += new_id[length-1];
        } 
    }

    answer = new_id;

    return answer;
}