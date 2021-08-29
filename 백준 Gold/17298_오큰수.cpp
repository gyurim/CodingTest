#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    int arr[1000001];
    int ans[1000001];
    stack<int> st;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = -1;
    }
        
    
    for (int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) 
        cout << ans[i] << " ";

    return 0;
}