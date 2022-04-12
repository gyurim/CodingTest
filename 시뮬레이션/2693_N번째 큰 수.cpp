#include <iostream>
#include <set> 
using namespace std;

int main() {
    
    int n;
    cin >> n;
    while(n--) {
        // 3번째 큰 값에 대해 출력 
        set<int, greater<int>> st; // 내림 차순 
        for (int i = 0; i < 10; i++) {
            int num;
            cin >> num;
            st.insert(num);
        }
        set<int, greater<int>>::iterator it = st.begin();
        for (int i = 0; i < 2; i++) {
            it++;
        }
        cout << *it << "\n";
    }
    return 0;
}