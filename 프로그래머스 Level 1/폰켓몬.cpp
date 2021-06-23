#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int nums_half_size = nums.size() / 2; 
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    // unique가 리턴하는 값은 자신이 바꾼 vector의 end 부분을 반환한다. 
    // unique 함수는 앞과 뒤의 원소들을 비교하기 때문에 반드시 정렬한 뒤 실행해야됨
    /* 
    unique가 작동하는 방식은 맨 처음값은 그대로 넣어주고 다음부터 중복이 있으면 pass, 중복이 없으면 맨 처음값 뒤에 넣어줌.
    즉, 중복이라고 판단되는 애들은 가만히 두고 중복 아닌 애들만 앞으로 가져온다고 생각하면 됨. 
    123 / 23 => 자신이 바꾼 애들 / 자신이 바꾸지 않는 애들 
    */
    int type_num = nums.size();

    answer = min(nums_half_size, type_num);

    return answer;
}

// int solution(vector<int> nums)
// {
//     int answer = 0;

//     // nums에 있는 숫자의 종류가 중요함 
//     vector <int> v;

//     sort(nums.begin(), nums.end());

//     v.push_back(nums[0]);

//     for (int i = 0; i < nums.size(); i++){
//         if (i > 0 && nums[i] != nums[i-1])
//             v.push_back(nums[i]);
//     }

//     if (v.size() > nums.size() / 2)
//         answer = nums.size() / 2;
//     else 
//         answer = v.size();
    
//     return answer;
// }

