#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    set<int> st;

    for (int i = 0; i < n; i++) {
        string s;

        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int num;
            cin >> num;

            auto it = st.find(num);
            if (it == st.end()) st.insert(num);

        } else if (cmd == "check") {
            int num;
            cin >> num;

            auto it = st.find(num);
            if (it == st.end()) cout << "0\n";
            else cout << "1\n";

        } else if (cmd == "remove") {
            int num;
            cin >> num;

            auto it = st.find(num);
            if (it != st.end()) st.erase(num);

        } else if (cmd == "toggle") {
            int num;
            cin >> num;

            auto it = st.find(num);
            if (it != st.end()) st.erase(num);
            else st.insert(num);

        } else if (cmd == "all") {
            auto it = st.begin();
            for (int j = 1; j <= 20; j++) {
                if (*it != j) {
                    st.insert(j);
                } 
                it++;
            }
        } else { // empty 
            st.clear();
        }
    }
}

// 방법 1 
/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int num = 0;
    int bit = 0; // bit를 반드시 0으로 초기화해줘야함

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
       
        if (cmd == "add") { // and 연산 
            cin >> num;
            bit |= (1 << num); // num번째 자리수를 1로 채움 

        } else if (cmd == "remove") {
            cin >> num;
            bit &= ~(1 << num);
        } else if (cmd == "check") {
            cin >> num;
            if (bit & (1 << num))  
                cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (cmd == "toggle") {
            cin >> num;
            bit ^= (1 << num);
        } else if (cmd == "all") {
            bit = (1 << 21) - 1;
        } else {
            bit = 0;
        }
    }
    return 0;
}
*/