// 방법 1
// 이해 안됨 ! ^^ 
#include <string>

using namespace std;

int solution(string word) {
    string v = "AEIOU";
    int a = word.size();

    for (int i = 0, b = 1; i < word.size(); i++, b*= 5) {
        a += v.rfind(word[i]) * 781 / b;
        // rfind는 뒤에서부터 찾고 find는 앞에서부터 찾음 (방향만 반대)
    }
    return a;
}

// 방법 2
/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> dictionary;
char alpha[] = {'A', 'E', 'I', 'O', 'U'};

// 백트래킹
void makeDic(string d, int step){
    if (step == 6) return;

    if (d != "") dictionary.push_back(d);
    
    for (auto c : alpha) {
        makeDic(d+c, step+1);
    }
}

int solution(string word) {
    int answer = 0;

    makeDic("", 0);

    answer = find(dictionary.begin(), dictionary.end(), word) - dictionary.begin() + 1;
    cout << answer;
    return answer;
}

int main() {
    solution("AAAAE");
}
*/