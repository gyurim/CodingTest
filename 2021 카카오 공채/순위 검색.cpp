//----------------------------------------------------------------------
// 방법 1
//----------------------------------------------------------------------
// 효율성 테스트 통과 
//----------------------------------------------------------------------
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

string l[4][4] = {{"-", "cpp", "java", "python"},
                {"-", "backend", "frontend"},
                {"-", "junior", "senior"},
                {"-", "chicken", "pizza"}};
 
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    // A. 전처리
    vector<vector<int>> L(108);
    for (auto s : info) {
        int v[4];
        int idx1 = 0, idx2 = s.find(" ", idx1); // s의 idx1번째 문자부터 찾는다. 

        for(int i = 0; i < 4; i++) {
            string cond = s.substr(idx1, idx2 - idx1);
            idx1 = idx2 + 1;
            idx2 = s.find(" ", idx1);
            v[i] = find(l[i], l[i]+4, cond) - l[i];
        }

        int score = stoi(s.substr(idx1, 10));

        for (int c1 : {0, v[0]}) { // 0(= "-")과 v[0](= "해당값")
            for (int c2 : {0, v[1]}) {
                for (int c3 : {0, v[2]}) {
                    for (int c4 : {0, v[3]}) {
                        // 3진법 -> 왜?? 
                        int idx = c1 * 27 + c2 * 9 + c3 * 3 + c4;
                        L[idx].push_back(score); // 총 16개의 index에 대해 score 저장해줌
                    }
                }
            }
        }
    }

    for (int i = 0; i < 108; i++) 
        sort(L[i].begin(), L[i].end());

    // B. 쿼리
    for (auto q : query) {
        int v[4];
        int idx1 = 0, idx2 = q.find(" ", idx1);

        for (int i = 0; i < 4; i++) {
            string cond = q.substr(idx1, idx2 - idx1);
            idx1 = idx2 + 5; // " and "
            idx2 = q.find(" ", idx1);
            v[i] = find(l[i], l[i] + 4, cond) - l[i]; // index 저장을 위한, - l[i] 
        }
        int target = stoi(q.substr(idx1 - 4, 10));
        int idx = v[0]*27 + v[1]*9 + v[2]*3 + v[3];
        // 맨 뒤에서 처음으로 같거나 큰 값이 나오는 index를 빼준다. -> index ~ 맨 끝까지의 개수가 나옴. 
        answer.push_back(L[idx].end() - lower_bound(L[idx].begin(), L[idx].end(), target));
    }
    return answer;
}

//----------------------------------------------------------------------
// 방법 2
//----------------------------------------------------------------------
// 효율성 테스트는 통과 못함 ㅠㅠ 
//----------------------------------------------------------------------
/*
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <utility>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

int binarySearch(int grade, vector<string> &query, vector<vector<string>> &info, vector<pair<int, int>> &infoIndex) {
    int cnt = 0;
    int lowerIndex = lower_bound(infoIndex.begin(), infoIndex.end(), make_pair(grade, 0), cmp) - infoIndex.begin();
    
    for (int i = lowerIndex; i < info.size(); i++) {
        int isSame = true;
        int index = infoIndex[i].second;

        for (int j = 0; j < query.size(); j++) {
            if (query[j] == "-") continue;
            if (query[j] != info[index][j]) {
                isSame = false;
                break;
            }
        }
        if (isSame) cnt++;
    }
    return cnt;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<pair<int, int>> infoGradeIndex;
    vector<vector<string>> infoString;

    for (int i = 0; i < info.size(); i++) {
        string s = info[i];

        vector<string> infos;

        while(s.find(" ") != string::npos) {
            int index = s.find(" ");
            infos.push_back(s.substr(0, index));
            s = s.substr(index+1, s.size()-1);
        }
        int grade = stoi(s);
        
        infoGradeIndex.push_back(make_pair(grade, i));
        infoString.push_back(infos);
    }

    sort(infoGradeIndex.begin(), infoGradeIndex.end());

    for (int i = 0; i < query.size(); i++) {
        string s = query[i];
        vector<string> infos;

        while (s.find(" and ") != string::npos) {
            int index = s.find(" and ");
            infos.push_back(s.substr(0, index));
            s = s.substr(index + 5, s.size()-1);
        }
        
        if (s.find(" ") != string::npos) {
            int index = s.find(" ");
            infos.push_back(s.substr(0, index));
            s = s.substr(index+1, s.size()-1);
        }
        int grade = stoi(s);
        answer.push_back(binarySearch(grade, infos, infoString, infoGradeIndex));
    }
    return answer;
}

int main() {
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    solution(info, query);
}
*/

//----------------------------------------------------------------------
// 방법 3
//----------------------------------------------------------------------
// 정확성 테스트 통과, 효율성 테스트 통과 X => 정규표현식 사용법 확인하는 용으로 기록해둠
// 정규표현식은 시간복잡도가 O(N) 따라서 효율성 통과하기 위해서는 사용 자제해야됨. 
//----------------------------------------------------------------------

/*
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>
#include <iostream>
#include <utility>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

int binarySearch(int grade, vector<string> &query, vector<vector<string>> &info, vector<pair<int, int>> &infoIndex) {
    int cnt = 0;
    int lowerIndex = lower_bound(infoIndex.begin(), infoIndex.end(), make_pair(grade, 0), cmp) - infoIndex.begin();
    for (int i = lowerIndex; i < info.size(); i++) {
        int isSame = true;
        int index = infoIndex[i].second;

        for (int j = 0; j < query.size(); j++) {
            if (query[j] == "-") continue;
            if (query[j] != info[index][j]) {
                isSame = false;
                break;
            }
        }

        if (isSame) cnt++;
    }
    return cnt;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<pair<int, int>> infoGradeIndex;
    vector<vector<string>> infoString;

    for (int i = 0; i < info.size(); i++) {
        string s = info[i];
        regex pattern ("\\d+");
        smatch match;

        if (regex_search(s, match, pattern)) {
            infoGradeIndex.push_back(make_pair(stoi(match.str()), i));
        }

        vector<string> infos;

        while(s.find(" ") != string::npos) {
            int index = s.find(" ");
            infos.push_back(s.substr(0, index));
            s = s.substr(index+1, s.size()-1);
        }
        infoString.push_back(infos);
    }

    sort(infoGradeIndex.begin(), infoGradeIndex.end());

    for (int i = 0; i < query.size(); i++) {
        string s = query[i];
        vector<string> infos;
        int grade = 0;

        regex pattern ("\\d+");
        smatch match;

        if (regex_search(s, match, pattern)) {
            grade = stoi(match.str());
        }

        while (s.find(" and ") != string::npos) {
            int index = s.find(" and ");
            infos.push_back(s.substr(0, index));
            s = s.substr(index + 5, s.size()-1);
        }
        
        if (s.find(" ") != string::npos) {
            int index = s.find(" ");
            infos.push_back(s.substr(0, index));
        }

        answer.push_back(binarySearch(grade, infos, infoString, infoGradeIndex));
    }

    return answer;
}

int main() {
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    solution(info, query);
}
*/