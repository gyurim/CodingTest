// 2022.04.13 
// 구글링해서 품. 다시 풀기 

#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// 최소성 확인 
bool possi(vector<int> vec, int now) {
    for (int i = 0; i < vec.size(); i++) {
        // ans에 있던 조합들을 탐색해서 기존에 있었던 조합이면 false 리턴 
        if ((vec[i] & now) == vec[i]) 
            return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int rowSize = (int)relation.size();
    int colSize = (int)relation[0].size();
    vector<int> ans;

    // 조합 경우의 수 
    /*
    1(0001) - 학번 
    2(0010) - 이름 
    3(0011) - 이름, 학번 
    4(0100) - 전공
    ...
    15(1111) - 학번, 이름, 전공, 학년 
    */

    for(int i = 1; i < (1 << colSize); i++) {
        set<string> s;
        for (int j = 0; j < rowSize; j++) {
            string now = "";
            for (int k = 0; k < colSize; k++) {
                // 선택된 컬럼과 일치한다면 
                if (i & (1 << k))  
                    now += relation[j][k];
            }
            // string 타입의 set 컨테이너를 활용해서 선택된 column들의 값들을 붙여서 insert 해줌 
            s.insert(now);
        }
        // s.size() == rowSize => 중복체크 
        // set 컨테이너 자체가 중복이 없는 컨테이너라서 총 row의 개수와 set의 size를 비교하면 유일성 여부 알 수 있음 
        if (s.size() == rowSize && possi(ans, i))
            ans.push_back(i);
    }
    return (int)ans.size();
}