#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string cmd;
    vector<int> st;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;

            st.push_back(x);
        } else if (cmd == "top") {
            if (st.size() > 0) 
                cout << st[st.size()-1] << "\n"; 
            else 
                cout << "-1\n";
        } else if (cmd == "pop") {
            if (st.size() > 0) {
                cout << st[st.size()-1] << "\n";
                st.erase(st.end()-1);
            }
            else 
                cout << "-1\n";
        } else if (cmd == "size") {
            cout << st.size() << "\n";
        } else if (cmd == "empty") {
            if (st.size() > 0) 
                cout << "0\n";
            else 
                cout << "1\n";
        } 
    }
    return 0;
}