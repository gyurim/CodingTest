#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(string expression)
{
    long long answer = 0;
    // 0~9의 아스키코드는 48~57
    string number;
    vector<long long> numbers;
    vector<char> ops;
    vector<char> priority;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] >= 48 && expression[i] <= 57) {
            number += expression[i];
        }
        else
        {
            ops.push_back(expression[i]);
            if (find(priority.begin(), priority.end(), expression[i]) == priority.end()) // expression에서 일치하는 게 없을 경우, 마지막 end를 반환  
                priority.push_back(expression[i]);
                // 중복을 제거해주는 unique, erase 함수 대신 이 코드를 사용했더니 시간초과 에러가 해결됨...
                // 이렇게 하는게 연산 속도가 더 낫나보다.. 
            numbers.push_back(stoll(number)); // string to long long : stoll() / string to int : stoi()
            number = "";
        }

        if (i == expression.size() - 1) {
            numbers.push_back(stoll(number));
        }
    }

    // priority = ops; 
    // priority.erase(unique(priority.begin(), priority.end()), priority.end());
    // 중복이 되어도 넣어준 것이 문제일듯;
    // 연산자의 우선순위를 지정해주는 priority 벡터에 중복을 제거해줘야 시간 초과가 나지 않는다.
    sort(priority.begin(), priority.end());

    do{
        vector<char> tempOps = ops;
        vector<long long> tempNumbers = numbers;

        for (int i = 0; i < priority.size(); i++)
        {
            for (int j = 0; j < tempOps.size(); j++)
            {
                if (priority[i] == tempOps[j])
                {
                    long long result = 0;
                    if (priority[i] == '*')
                    {
                        result = tempNumbers[j] * tempNumbers[j + 1];
                    }
                    else if (priority[i] == '+')
                    {
                        result = tempNumbers[j] + tempNumbers[j + 1];
                    }
                    else if (priority[i] == '-')
                    {
                        result = tempNumbers[j] - tempNumbers[j + 1];
                    }
                    tempNumbers.erase(tempNumbers.begin() + j);
                    tempNumbers.insert(tempNumbers.begin() + j, result);
                    tempNumbers.erase(tempNumbers.begin() + j + 1);
                    tempOps.erase(tempOps.begin() + j);
                    j--; // 이것 때문에 틀렸었음 다시 체크해주는 과정 필요!
                    // 4-3-2-1 이 반례였다. 얘가 0이 나왔음.
                }
            }
        }

        if (answer <= abs(tempNumbers[0])) // 절댓값 
            answer = abs(tempNumbers[0]);
    } while (next_permutation(priority.begin(), priority.end()));

    return answer;
}

int main()
{
    string expression;
    cin >> expression;

    cout << solution(expression);
    return 0;
}