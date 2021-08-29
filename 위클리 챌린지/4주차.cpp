#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> m;

int findLanguage(string lang, int grade) {
    map<string, int>::iterator it;
    int pref = grade;

    if ((it = m.find(lang)) != m.end()) {
        pref *= it -> second;
    } else {
        pref = 0;
    }
    return pref;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<int, vector<string>> result;
    
    for (int i = 0; i < languages.size(); i++) {
        m.insert(make_pair(languages[i], preference[i]));
    }

    int max = 0;

    for (int i = 0; i < table.size(); i++) {
        string s = table[i];
        stringstream ss(s);
        string token;
        bool isJob = true;
        string job;
        int grade = 5;
        int total = 0;

        while (ss >> token) {
            if (isJob) {
                job = token;
                isJob = false;
            } else {
                total += findLanguage(token, grade);
                grade--;
            }
        }
        result[total].push_back(job);
        max = (max <= total) ? total : max;
    }

    sort(result[max].begin(), result[max].end());
    answer = result[max].front();

    return answer;
}

/*

int findLanguage(string lang, int grade) {
    map<string, int>::iterator it;
    int pref = grade;

    if ((it = m.find(lang)) != m.end()) {
        pref *= it -> second;
    } else {
        pref = 0;
    }
    return pref;
}

bool cmp(const pair<string, int>& a, const pair<string, int>& b) { // map의 value를 기준으로 내림차순 
    if (a.second == b.second) return a.first < b.first; // 같을때는 알파벳 순서가 더 빠른 값(first의 값이 더 작다)이 먼저오게 한다. 
    else return a.second > b.second;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string, int> result;
    
    for (int i = 0; i < languages.size(); i++) {
        m.insert(make_pair(languages[i], preference[i]));
    }

    for (int i = 0; i < table.size(); i++) {
        string s = table[i];
        stringstream ss(s);
        string token;
        bool isJob = true;
        string job;
        int grade = 5;
        int total = 0;

        while (ss >> token) {
            if (isJob) {
                job = token;
                isJob = false;
            } else {
                total += findLanguage(token, grade);
                grade--;
            }
        }
        result.insert(make_pair(job, total));
    }

    vector<pair<string, int>> vec(result.begin(), result.end());
    sort(vec.begin(), vec.end(), cmp);

    answer = vec[0].first;

    return answer;
}
*/