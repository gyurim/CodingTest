#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 누적합 

int solution(vector<int> arr, vector<int> brr) {
    int answer = 0;
    int arr_sum = 0;
    int brr_sum = 0;

    // answer는 arr.size()를 넘을 수 없다. 
    for (int i = 0; i < arr.size(); i++) { 
        arr_sum += arr[i];
        brr_sum += brr[i];

        if (arr_sum != brr_sum) {
            answer++;
            arr[i+1] += (arr[i] - brr[i]);
            arr_sum = brr_sum; // i까지 arr[i] = brr[i] 맞춘 것 
        }
    }
    return answer;
}

int main() {
    vector<int> arr {6, 2, 2, 6};
    vector<int> brr {4, 4, 4, 4};
    cout << solution(arr, brr);
    return 0;
}