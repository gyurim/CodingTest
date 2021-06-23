#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long getExpressionResult(vector<long long> numbers, vector <char> ops, vector <char> priority){
    for (int i = 0; i < priority.size(); i++){
        for (int j = 0; j < ops.size(); j++){
            if (priority[i] == ops[j]){
                int result = 0;
                if (priority[i] == '*'){
                    result = numbers[j] * numbers[j+1];
                } else if (priority[i] == '+'){
                    result = numbers[j] + numbers[j+1];
                } else if (priority[i] == '-'){
                    result = numbers[j] - numbers[j+1];
                }
                
                numbers.erase(numbers.begin() + j);
                numbers.insert(numbers.begin() + j, result);
                numbers.erase(numbers.begin() + j + 1);
                ops.erase(ops.begin() + j);
            }
        }
    }
    return numbers[0];
}

long long solution(string expression) {
    long long answer = 0;

    // 0~9의 아스키코드는 48~57
    string number;
    vector <long long> numbers;
    vector <char> ops;
    vector <char> priority;
    vector <long long> results;

    for (int i = 0; i < expression.length(); i++){
        if (expression[i] >= 48 && expression[i] <= 57){
            number += expression[i];
        } else {
            ops.push_back(expression[i]);
            numbers.push_back(stoi(number)); // string to int : stoi()
            number = "";
        }
        
        if (i == expression.length()-1)
            numbers.push_back(stoi(number)); 
    }
    
    priority = ops;
    sort(priority.begin(), priority.end());

    do {
        results.push_back(abs(getExpressionResult(numbers, ops, priority)));
    } while (next_permutation(priority.begin(), priority.end()));

    answer = *max_element(results.begin(), results.end());

    return answer;
}

int main(){
    string expression;
    cin >> expression;
    
    cout << solution(expression);
    return 0;
}