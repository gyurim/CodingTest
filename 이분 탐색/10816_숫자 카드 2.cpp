#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    int arr[500002];
    vector<int> output;

    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N); // 배열    sort할 때 첫번째 인자, 두번째 인자에 들어갈 내용 외우기 

    cin >> M;

    for (int i = 0; i < M; i++) {
        int find;
        cin >> find;

        // arr에서 find보다 같거나 큰 값이 나오는 첫번째 위치의 Index 반환하기 위해서는 
        //lower_bound()에서 배열 첫번째 주소를 가리키는 배열의 이름을 빼주면 됨.
        int startindex = lower_bound(arr, arr + N, find) - arr; // target보다 같거나 큰 값이 나오는 처음 위치
        int endindex = upper_bound(arr, arr + N, find) - arr; // target보다 첫번째로 큰 값이 나오는 위치 
        
        output.push_back(endindex - startindex);
    }

    for (auto o : output)
        cout << o << " "; 
    return 0;
}

/*
Map은 이분탐색 기반 stl인데, 왜 map을 쓰면 시간초과 나고
upper_bound, lower_bound를 쓰면 시간초과가 X ? 

*/

// #include <iostream>
// #include <map>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int main() {
//     int N, M;
//     map<long long, int> m;
//     map<long long, int>::iterator it;
//     vector<int> output;
    

//     cin >> N;
    
//     for (int i = 0; i < N; i++) {
//         long long num;
//         cin >> num;

//         if ((it = m.find(num)) != m.end())
//             it -> second++;
//         else 
//             m.insert(make_pair(num, 1));     

            // find~ 대신 // m[num]++; 사용! 
//     }

//     cin >> M;

//     for (int i = 0; i < M; i++) {
//         long long find;
//         cin >> find;
        
//         it = m.lower_bound(find); // target보다 같거나 큰 값이 나오는 처음 위치 & lower_bound 사용법 

//         if (it->first == find) output.push_back(it->second);
//         else output.push_back(0);
//     }

//     for (auto o : output) {
//         cout << o << " ";
//     }
    
//     return 0;
// }