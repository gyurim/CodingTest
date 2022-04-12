#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

bool errorCheck(long result) {
    long reResult = abs(result);
    
    if (reResult > 1000000000) {
        return false;
    }
    return true;
}

long divAndMod(int first, int second, string cmp) {
    long result = 0;
    bool shareSign = false;
    bool remainderSign = (second >= 0) ? true : false;
    if ((first < 0 && second < 0) || (first > 0 && second > 0)) 
        shareSign = true; 

    first = (first < 0) ? abs(first) : first;
    second = (second < 0) ? abs(second) : second;

    if (cmp == "MOD") {
        result = first % second;
        result = (remainderSign == false) ? -result : result;
    } else {
        result = first / second;
        result = (shareSign == false) ? -result : result;
    }
    return result;
}

void calculate(vector<int> goStack, vector<string> cmp_vec, queue<int> num_vec) {
    bool isEndFlag = false;
    for (int i = 0; i < cmp_vec.size(); i++) {
        if (cmp_vec[i] == "NUM") {
            if (num_vec.front() > 1000000000) {
                isEndFlag = true;
                break;
            }
            goStack.push_back(num_vec.front());
            num_vec.pop();
        } else if (cmp_vec[i] == "POP") {
            if (goStack.size() == 0) {
                isEndFlag = true;
                break;
            }
            goStack.erase(goStack.begin() + goStack.size()-1);
        } else if (cmp_vec[i] == "INV") {
            if (goStack.size() == 0) {
                isEndFlag = true;
                break;
            }
            goStack[goStack.size()-1] = - goStack[goStack.size()-1];
        } else if (cmp_vec[i] == "DUP") {
            if (goStack.size() == 0) {
                isEndFlag = true;
                break;
            }
            goStack.push_back(goStack[goStack.size()-1]);
        } else if (cmp_vec[i] == "SWP") {
            if (goStack.size() < 2) {
                isEndFlag = true;
                break;
            }

            int tmp = goStack[goStack.size()-1];
            goStack[goStack.size()-1] = goStack[goStack.size()-2];
            goStack[goStack.size()-2] = tmp;

        } else if (cmp_vec[i] == "ADD") {
            if (goStack.size() < 2) {
                isEndFlag = true;
                break;
            }
            long result = (goStack[goStack.size()-1] + goStack[goStack.size()-2]);
            if (!errorCheck(result)) {
                isEndFlag = true;
                cout << "errorCheck = false\n";
                break;
            } else {
                goStack.erase(goStack.begin() + goStack.size()-1);
                goStack.erase(goStack.begin() + goStack.size()-1);
                goStack.push_back(result);
            }
        } else if (cmp_vec[i] == "SUB") {
            if (goStack.size() < 2) {
                isEndFlag = true;
                break;
            }
            long result = (goStack[goStack.size()-2] - goStack[goStack.size()-1]);
            if (!errorCheck(result)) {
                isEndFlag = true;
                break;
            }
            goStack.erase(goStack.begin() + goStack.size()-1);
            goStack.erase(goStack.begin() + goStack.size()-1);
            goStack.push_back(result);

        } else if (cmp_vec[i] == "MUL") {
            if (goStack.size() < 2) {
                isEndFlag = true;
                break;
            }
            long result = (goStack[goStack.size()-2] * goStack[goStack.size()-1]);
            
            if (!errorCheck(result)) {
                isEndFlag = true;
                break;
            }
            goStack.erase(goStack.begin() + goStack.size()-1);
            goStack.erase(goStack.begin() + goStack.size()-1);
            goStack.push_back(result);

        } else if (cmp_vec[i] == "DIV") {
            if (goStack.size() < 2) {
                isEndFlag = true;
                break;
            }
            if (goStack[goStack.size()-1] == 0) {
                isEndFlag = true;
                break;
            }
            
            long result = divAndMod(goStack[goStack.size()-2], goStack[goStack.size()-1], "DIV");
            
            if (!errorCheck(result)) {
                isEndFlag = true;
                break;
            }
            
            goStack.erase(goStack.begin() + goStack.size()-1);
            goStack.erase(goStack.begin() + goStack.size()-1);
            goStack.push_back(result);
        } else if (cmp_vec[i] == "MOD") {
            if (goStack.size() < 2) {
                isEndFlag = true;
                break;
            }
             if (goStack[goStack.size()-1] == 0) {
                isEndFlag = true;
                break;
            }
            long result = divAndMod(goStack[goStack.size()-2], goStack[goStack.size()-1], "MOD");
            
            if (!errorCheck(result)) {
                isEndFlag = true;
                break;
            }

            goStack.erase(goStack.begin() + goStack.size()-1);
            goStack.erase(goStack.begin() + goStack.size()-1);
            goStack.push_back(result);
        }
    }
    if (isEndFlag) {
        cout << "ERROR\n";
        return;
    } else if (goStack.size() == 1) {
        cout << goStack[0] << endl;
        return;
    } else {
        cout << "ERROR\n";
        return;
    }
}

void init(vector<int> goStack, vector<string> cmp_vec, queue<int> num_vec) {
    cmp_vec.clear();
    
    while (num_vec.size() > 0) {
        num_vec.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string cmp;

    while(1) {
        cin >> cmp;

        if (cmp == "QUIT") break;
        else {
            vector<string> cmp_vec;
            queue<int> num_vec;
            while(1) {
                if (cmp == "END") break;

                if (cmp == "NUM") {
                    int num;
                    cin >> num;
                    num_vec.push(num);
                } 
                cmp_vec.push_back(cmp);
                cin >> cmp;
            }

            int renum;
            cin >> renum;
            int first_num;
            
            while (renum--) {
                vector<int> goStack;
                cin >> first_num;
                goStack.push_back(first_num);
                calculate(goStack, cmp_vec, num_vec);
                init(goStack, cmp_vec, num_vec);
            }
        }
    }
    return 0;
}