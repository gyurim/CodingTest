#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = 0;

    vector<long long> numbers;
    vector<char> ops;
    vector<char> priority {'+', '-', '*'};

    string number;
    for (auto e : expression) {
        if (e == '*' || e == '+' || e == '-') {
            ops.push_back(e);
            numbers.push_back(atoll(number.c_str()));
            number = "";
        } else number += e;
    }
    numbers.push_back(atoll(number.c_str()));

    sort(priority.begin(), priority.end());
    do {
        vector<char> cpy_ops = ops;
        vector<long long> cpy_num = numbers;

        for (auto p_op : priority) {

            for (int i = 0; i < cpy_ops.size(); ) {
                if (p_op == cpy_ops[i]) { // i++ 하지 않음. 다시 검사해야되기 때문 
                    long long ab;
                    if (p_op == '*') ab = cpy_num[i] * cpy_num[i+1];
                    else if (p_op == '+') ab = cpy_num[i] + cpy_num[i+1];
                    else if (p_op == '-') ab = cpy_num[i] - cpy_num[i+1];

                    auto it = cpy_num.begin() + i;
                    cpy_num[i] = ab;
                    it++;
                    cpy_num.erase(it);

                    cpy_ops.erase(cpy_ops.begin() + i);
                } else i++; 
            }
        }

        answer = (answer < abs(cpy_num[0])) ? abs(cpy_num[0]) : answer;
    } while (next_permutation(priority.begin(), priority.end()));

    return answer;
}