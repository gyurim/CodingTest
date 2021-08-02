#include <iostream>
using namespace std;

/*
코딩테스트에서 sort STL 사용하지 못할 시, 퀵 소트가 아닌 merge sort 사용해야됨! 
퀵 소트 => 최악: O(n^2), 최고: O(nlogn), 평균: O(nlogn)
머지 소트 => 최악: O(nlogn), 평균: O(nlong) (하지만, 평균의 경우 퀵 소트가 빠름!)
*/

int n = 8;
int arr[1000001] = {6, -8, 1, 12, 8, 3, 7, -7};
int tmp[1000001];

void merge(int st, int en) {
    cout << "merge() 호출 [" << st << ", " << en << "]\n"; 

    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;
    
    for (int i = st; i < en; i++) {
        if (ridx == en) tmp[i] = arr[lidx++];
        else if (lidx == mid) tmp[i] = arr[ridx++];
        else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    
    for (int i = st; i < en; i++) {
        arr[i] = tmp[i];
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge_sort(int st, int en) {
    cout << "merge_sort() 호출 [" << st << ", " << en << "]\n"; 
    if (en - st == 1) {
        cout << "merge_sort return()"<< endl;
        return;
    }
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    merge_sort(0, n);
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}