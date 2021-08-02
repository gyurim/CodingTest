#include <iostream>
using namespace std;

int n = 8;
int arr[1000001] = {6, -8, 1, 12, 8, 3, 7, -7};

void quick_sort(int st, int en) {
    cout << "quick_sort() 호출 [" << st << ", " << en << "]\n"; 
    if (en <= st + 1) return;
    int pivot = arr[st];
    cout << "pivot = arr[" << st << "] = " << pivot << endl;
    int l = st + 1;
    int r = en - 1;

    while(1) {
        while (l <= r && arr[l] <= pivot) l++; // pivot보다 큰 애를 만날때까지 l++
        while (l <= r && arr[r] >= pivot) r--; // pivot보다 작은 애를 만날때까지 r--
        // l은 현재 pivot보다 큰 값을 가리킴. r은 pivot보다 작은 값을 가리킴 
        if (l > r) break;
        swap(arr[l], arr[r]); 
    }
    swap(arr[st], arr[r]); // r이 l의 왼쪽에 가는 순간, r과 pivot의 자리를 바꾸면 됨 
    quick_sort(st, r);
    quick_sort(r+1, en);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    quick_sort(0, n);
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";

    return 0;
}