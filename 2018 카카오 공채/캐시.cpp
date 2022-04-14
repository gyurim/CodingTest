// 2022.04.14
// queue, deque(덱), stack은 iterator 접근 안됨. 따라서 find 함수 사용 X
// unordered_set은 erase할 때 erase(--s.end())가 안 됐음.. 
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> vec;
    vector<int> time;

    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower); // 소문자로 
        // find
        bool isFind = false;
        int idx = -1;
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] == city) {
                isFind = true;
                idx = j;
                break;
            }
        }

        if (isFind) {
            time[idx] = i; // 시간 갱신 (이 부분 빠져서 계속 틀렸음)
            answer += 1;
        } else {
            if (cacheSize == 0) {
                answer += 5;
                continue;
            }
            if (vec.size() < cacheSize) {
                vec.push_back(city);
                time.push_back(i); 
                answer += 5;
            } else {
                int leastTime = 100005;
                int leastIdx = -1;
                for (int j = 0; j < time.size(); j++) {
                    if (leastTime > time[j]) {
                        leastTime = time[j];
                        leastIdx = j;
                    }
                }
                time[leastIdx] = i;
                vec[leastIdx] = city;
                answer += 5;
            }
        }
    }
    return answer;
}

int main() {
    vector<string> cities { "LA",  "LA", "LA"};
    cout << solution(5, cities);
    return 0;
}