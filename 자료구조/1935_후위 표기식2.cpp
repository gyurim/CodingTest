#include <iostream>
#include <vector>
#include <stack>

using namespace std;

double calculate(double a, double b, char c) {
    if (c == '*') return a * b;
    else if (c == '+') return a + b;
    else if (c == '-') return a - b;
    else return a / b;
}

int main() {
    int n;
    string s;
    vector<int> grade;
    vector<char> alphabet;
    stack<double> stack;

    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;
        grade.push_back(g);
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 'A' || 'Z' < s[i]) {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            double c = calculate(a, b, s[i]);
            stack.push(c);
            cout << a << s[i] << b << " = " << c << endl;
        } else {
            auto it = find(alphabet.begin(), alphabet.end(), s[i]);
            if (it == alphabet.end()) {
                alphabet.push_back(s[i]);
                stack.push(grade[alphabet.size()-1]);
            } else {
                stack.push(grade[it - alphabet.begin()]); // 가리키는 값의 index 
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << stack.top();
    return 0;
}