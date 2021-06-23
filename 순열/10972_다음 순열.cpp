#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int perm[10010];
    vector <int> v;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> perm[i];
    }

    copy(perm, perm + n, back_inserter(v));

    /*-------------------------방법 1--------------------------
    ----------------------------------------------------------*/
    int index = -1;    
    for (int i = n-1; i > 0; i--){
        if(perm[i-1] < perm[i]){
            index = i-1;
            break;
        }
    }

    if (index != -1){
        int minIdx = index+1;
        int min = perm[minIdx];
        for (int i = index+1; i < n; i++){
            // 조건 잊지 말기 ! 현재의 값은 바꾸고자하는 index의 값보다 커야한다. 
            if (min >= perm[i] && perm[i] > perm[index]){
                min = perm[i];
                minIdx = i;
            }
        }

        int temp = perm[index];
        perm[index] = min;
        perm[minIdx] = temp;

        // perm을 벡터로 선언 -> 특정 위치부터 정렬하는 방법을 모르겠음 
        sort(perm + index + 1, perm + n);
        
        for (int i = 0; i < n; i++){
            cout << perm[i] << " ";
        }
    } else cout << "-1";
    
    cout << "\n";
    cout << "\n";

    /*-------------------------방법 2--------------------------
        next_permutation() stl 사용 -> #include <algorithm> 
    ----------------------------------------------------------*/

    // 매열을 벡터에 복사
    next_permutation(v.begin(), v.end());
    for (int i = 0; i < n; i++){
            cout << v[i] << " ";
    }
    return 0;
}