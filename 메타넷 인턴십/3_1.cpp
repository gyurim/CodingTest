#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int solution(int K, vector<string> user_scores)
{
    int answer = 0;

    vector<pair<long long, long long>> v;
    vector<string> users;
    vector<pair<long long, long long>> ranks(K, {0, 0});
    long long index = 1;

    users.push_back("_");

    long long us_len = user_scores.size();

    for (long long i = 0; i < us_len; i++)
    {
        string s = user_scores[i];

        istringstream iss(s);
        string user;
        long long score;
        iss >> user >> score;

        bool flag = false;
        for (long long j = 0; j < index; j++)
        {
            if (users[j] == user)
            {
                flag = true;
                v.push_back({j, score});
            }
        }
        if (!flag)
        {
            users.push_back(user);
            v.push_back({index, score});
            index++;
        }
    }

    vector<long long> cur_score(users.size() + 1, 0);

    for (long long i = 0; i < us_len; i++)
    {
        long long vid = v[i].first;
        long long vscore = v[i].second;

        // 랭크 변경 체크 
        if (cur_score[vid] < vscore)
        { 
            cur_score[vid] = vscore;
            vector<pair<long long, long long>> new_ranks;

            for (int j = 0; j < K; j++)
            {
                if (ranks[j].second < vscore)
                {
                    new_ranks.push_back({vid, vscore});
                    bool flg = false;
                    for (int k = j; k < K - 1; k++)
                    {
                        if (ranks[j].first == vid)
                        {
                            flg = true;
                            continue;
                        }
                        new_ranks.push_back(ranks[k]);
                    }
                    if (flg)
                        new_ranks.push_back(ranks[K - 1]);
                    break;
                }
                else
                    new_ranks.push_back(ranks[j]);
            }
            for (int j = 0; j < K; j++)
            {
                if (new_ranks[j].first != ranks[j].first)
                {
                    answer++;
                    break;
                }
            }
            ranks.clear();
            for (int j = 0; j < K; j++)
                ranks.push_back(new_ranks[j]);
        }
    }
    return answer;
}

int main() {
    vector<string> vec = {"alex111 100", "cheries2 200", "coco 150", "luna 100", "alex111 120", "coco 300", "cheries2 110"};
    solution(1, vec);
    return 0;
}