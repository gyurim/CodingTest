#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> dq;

void makearr(string &numbers) {
    string temp;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] >= '0' && numbers[i] <= '9') {
            temp += numbers[i];
        } else if (numbers[i] == ',' || numbers[i] == ']') {
            if (!temp.empty()) {
                dq.push_back(stoi(temp));
                temp.clear();
            }
        } else if (numbers[i] == '[') continue;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        bool isEnd = false;
        bool isreverse = false;

        string func, numbers;
        int n;

        cin >> func;
        cin >> n;
        cin >> numbers;
        
        makearr(numbers);

        for (int j = 0; j < func.size(); j++) {
            if (func[j] == 'R') {
                isreverse = !isreverse;
            } else {
                if (dq.size() == 0) {
                    cout << "error" << endl;
                    isEnd = true;
                    break;
                } else {
                    if (isreverse) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }
        
        if (isEnd) continue;
        // 출력 
        cout << "[";
        if (isreverse) {
            while(!dq.empty()) {
                cout << dq.back();
                if (dq.size() != 1) cout << ",";
                dq.pop_back();
            }
        } else {
            while(!dq.empty()) {
                cout << dq.front();
                if (dq.size() != 1) cout << ",";
                dq.pop_front();
            }
        }
        cout << "]" << endl;
    }
    return 0;
}