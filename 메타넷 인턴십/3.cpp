#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int solution(int K, vector<string> user_scores) {
    int answer = 0;

    vector<pair<string, long long>> vec;
    
    for (string uscore : user_scores) {
        istringstream iss(uscore);
        string user;
        long long score;
        iss >> user >> score;

        vector<pair<string, long long>> new_rank;

        if (new_rank.size() == 0) new_rank.push_back({user, score});

        for (int i = 0; i < vec.size(); i++) {
            pair<string, long long> v = vec[i];

            if (v.first == user) {
                if (v.second < score) {
                    v.second = score;

                    // 다른 사람 점수보다 높아질 경우, k 이내의 등수라면 answer++
                    // 그리고 등수 이동도 필요함 
                    for (int j = 0; j < i; j++) {
                        pair<string, int> diff = vec[j];

                        if (diff.second < score) {
                            pair<string, int> temp = diff;
                            vec[j].first = user;
                            vec[j].second = score;
                            vec[i].first = temp.first;
                            vec[i].second = temp.second;

                            if (j <= K - 1) answer++;
                            break;
                        }
                    }
                } else continue;
            }

            // 만약 존재하지 않는다면 처음 들어오는 것으로 간주 
            if (i == vec.size()-1 && v.first != user) {
                
                for (int j = 0; j <= i; j++) {
                    pair<string, int> diff = vec[j];

                    if (diff.second < score) {
                        pair<string, int> temp = diff;
                        vec[j].first = user;
                        vec[j].second = score;
                        // vec[i].first = temp.first;
                        // vec[i].second = temp.second;

                        if (i < K - 1) answer++;
                        break;
                    }

                    if (j == i) {
                        vec.push_back({user, score});
                        if (i < K - 1) answer++;
                    }
                }
            }
        }
         for (int ii = 0; ii < vec.size(); ii++) {
            cout << vec[ii].first << " " << vec[ii].second << endl;
        }
        cout << endl;

        vec.clear();

        for (auto nr : new_rank) {
            vec.push_back(nr);
        }
    }

    return answer;
}

int main() {
    vector<string> vec = {"alex111 100", "cheries2 200", "coco 150", "luna 100", "alex111 120", "coco 300", "cheries2 110"};
    solution(3, vec);
    return 0;
}