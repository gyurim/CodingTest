#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands){
    vector<int> answer;

    for (int cnt = 0; cnt < commands.size(); cnt++) {
        vector<int> v;

        int i = commands[cnt][0];
        int j = commands[cnt][1];
        int k = commands[cnt][2];

        for (int cnt2 = i-1; cnt2 < j-1; cnt2++){
            v.push_back(array[cnt2]);
        }

        sort(v.begin(), v.end());

        answer.push_back(v[k]);
    }

    //간결.ver
    /* 
    vector<int> temp;

    for (int i = 0; i < commands.size(); i++){
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2] - 2]);
    }
    */

    return answer;
}