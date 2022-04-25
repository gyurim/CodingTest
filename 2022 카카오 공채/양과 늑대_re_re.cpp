#include <string>
#include <vector>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    return answer;
}

int main(){
    vector<int> info {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges;
    string s = "[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            if (s[i-1] == ']') continue;
            int a = s[i-1] - '0';
            int b = s[i+1] - '0';
            edges.push_back({a, b});
            i++;
        }
    }
    solution(info, edges);
}