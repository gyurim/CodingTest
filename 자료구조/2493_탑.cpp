#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int main() {
    int n, height;
    stack<pair<int, int>> s;
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &height);

        while (!s.empty()) {
            if (height <= s.top().second) {
                cout << s.top().first << " ";
                break;
            }
            s.pop(); // 어차피 현재의 height 보다 작은 값은 뒤에 나오는 height의 후보에 들지 못함 
        }
        if (s.empty()) printf("0 ");
        s.push(make_pair(i, height));
    }    
    return 0;
}

// 시간 초과 
// #include <iostream>
// #include <stdio.h> 
// #include <vector>

// using namespace std;

// int main() {
//     int n;
//     scanf("%d", &n);

//     vector<pair<int, int>> vec;

//     for (int i = 1; i <= n; i++){
//         int height;
//         scanf("%d", &height);
//         vec.push_back(make_pair(i, height));
//     }
//     printf("0 ");
//     for (int i = 1; i < n; i++) {
//         bool flag = false;
//         for (int j = i - 1; j >= 0; j--) {
//             if (vec.at(i).second <= vec.at(j).second) {
//                 printf("%d ", vec.at(j).first);
//                 flag = true;
//                 break;
//             } 
//         }
//         if (!flag) printf("0 ");
//     }
        
//     return 0;
// }