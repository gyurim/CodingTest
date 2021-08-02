#include <string>
#include <vector>
#include <iostream>

using namespace std;

// string solution(int n) {
//     string answer = "";
//     string arr[] = {"4", "1", "2", "4"};

//     int divide = n / 3;
//     int rest = n % 3;
//     if (rest == 0) divide -= 1;

//     if (divide <= 3) {
//         if (divide > 0) {
//             answer = arr[rest] + answer;
//             answer = arr[divide] + answer;
//         } else answer = arr[rest] + answer;
//     } else {
//         while (divide > 3) {
//             answer = arr[rest] + answer;
//             rest = divide % 3;
//             divide /= 3;
            
//             if (rest == 0) 
//                 divide -= 1;
//         }
//         answer = arr[rest] + answer;
//         answer = arr[divide] + answer;
//     }
//     return answer;
// }

// 방법 2 (구글링) 
string solution(int n) {
    string answer = "";
    string arr[] = {"4", "1", "2"};
    while(n) {
        answer = arr[n%3] + answer;
        if (n % 3 == 0) n = n / 3 - 1;
        else n = n / 3;
    }
    return answer;
}