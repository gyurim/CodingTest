#include <iostream>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int arr[100001];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int en = 0;
    int total = arr[0];
    int min = 0x7fffffff;

    for (int st = 0; st < n; st++) {
        while (en < n && total < s) {
            en++;

            if (en == n) break;
            total += arr[en];
        }
        if (en == n) break;
        min = (min > en - st + 1) ? en - st + 1 : min;
        
        total -= arr[st];
    }
}

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int &a, int &b) {
    if (a == b) return a > b;
    else return a > b;
}

int main() {
    int n, s;
    scanf("%d", &n);
    scanf("%d", &s);

    int arr[100001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int st, en = 0;
    int min = 0x7fffffff;
    int total = arr[st];
    
    for (int st = 0; st < n; st++) {
        while (en < n && total < s) {
            en++;
            if (en != n) total += arr[en]; // 이거 중요 .. (틀림 떴음)
        }
        if (en == n) break; // 이거 중요 .. (틀림 떴음)
        int length = en - st + 1;
        min = (min > length) ? length : min;
        total -= arr[st];
    }
    
    if (min != 0x7fffffff) printf("%d", min);
    else printf("0");
    
    return 0;
}
*/