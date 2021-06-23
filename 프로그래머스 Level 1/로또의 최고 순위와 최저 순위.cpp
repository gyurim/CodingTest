#include <string>
#include <vector>

using namespace std;

int getorder(int content){
    if (content == 6)
        return 1;
    else if (content == 5)
        return 2;
    else if (content == 4)
        return 3;
    else if (content == 3)
        return 4;
    else if (content == 2)
        return 5;
    else 
        return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int correct = 0;
    int zero = 0;


    for (int i = 0; i < 6; i++){
        if (lottos[i] == 0)
            zero += 1;

        for (int j = 0; j < 6; j++){
            if (win_nums[j] == lottos[i])
                correct += 1;
        }
    }

    answer.push_back(getorder(correct+zero));
    answer.push_back(getorder(correct));

    return answer;
}