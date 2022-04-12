#include <iostream>
using namespace std;

int n, m;
int arr[1000005];

int FindParent(int a) {
    if (arr[a] == a) return a;
    // 시간초과 해결방안 1)
    // arr[a] = FindParent(arr[a])해야 바로바로 찾은 parent가 적용되기 때문에 시간초과 안 걸림
    return arr[a] = FindParent(arr[a]);
}

void Union(int a, int b){
    int pa = FindParent(a);
    int pb = FindParent(b);

    // 시간초과 해결방안 2)
    // 합쳐줄 조건을 정해놔야함. 
    // 큰 수 -> 작은 수로 합쳐지기 
    if (pa > pb) arr[pa] = pb;
    else arr[pb] = pa;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    // 자기 자신으로 초기화 
    for (int i = 0; i <= n; i++)
        arr[i] = i;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 0) { // union
            Union(b, c);
        } else if (a == 1) { // find 
            if (FindParent(b) == FindParent(c)) 
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}