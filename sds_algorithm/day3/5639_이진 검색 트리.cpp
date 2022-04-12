#include <iostream>
#include <vector>
using namespace std;

#define L first
#define R second

pair<int, int> sibling[1000005];

void print_recursion(int cur)
{
    // 후위 순회 출력
    if (sibling[cur].L != 0)
    {
        print_recursion(sibling[cur].L);
    }
    if (sibling[cur].R != 0)
    {
        print_recursion(sibling[cur].R);
    }
    cout << cur << "\n";
}

int main()
{
    int root;
    cin >> root;
    int t;
    // 전위 순회로 입력받지만, 그냥 트리 만들면 됨
    while (cin >> t)
    {
        int st = root;
        while (true) {
            if (t < st) {
                if (sibling[st].L == 0){
                    sibling[st].L = t;
                    break;
                } else st = sibling[st].L;
            }
            if (t > st) {
                if (sibling[st].R == 0) {
                    sibling[st].R = t;
                    break;
                } else st = sibling[st].R;
            }
        }
    }
    print_recursion(root);

    return 0;
}