#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    do
    {
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            string input = data[i];
            vector<char>::iterator it_first = find(friends.begin(), friends.end(), input[0]);
            vector<char>::iterator it_second = find(friends.begin(), friends.end(), input[2]);
            char op = input[3];
            int distance = abs(it_first - it_second) - 1;
            int condition_distance = input[4] - '0';

            if (op == '=')
            {
                if (condition_distance == distance)
                {
                    flag++;
                } else break;
            }
            else if (op == '>')
            {
                if (condition_distance < distance)
                {
                    flag++;
                } else break;
            }
            else if (op == '<')
            {
                if (condition_distance > distance)
                {
                    flag++;
                } else break;
            }
        }

        if (flag == n)
            answer++;

    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}