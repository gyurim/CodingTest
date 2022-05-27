#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> alpha;
int l, c;

bool isVisit[20] = {false};

void func(int k, vector<char> arr) {
    if (arr.size() == l) { // k == l 이 아니라 arr.size() == l 인 경우를 백트레킹 조건으로 해줘야함 
        int mo_cnt = 0;
        int za_cnt = 0;

        for (auto a : arr) {
            if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
                mo_cnt++;
            else za_cnt++;
        }

        if (mo_cnt >= 1 && za_cnt >= 2) {
            for (auto a : arr)
                cout << a;
            cout << '\n';
        }
        return;
    }

    for (int i = k; i < c; i++) {
        arr.push_back(alpha[i]);
        func(i+1, arr); // i+1번째 값이 i번째 값보다 크게 하고 싶을 경우에는 파라미터를 i+1로 넘겨줘야함..! (not k+1)
        arr.pop_back(); 
    }
}

int main() {
    cin >> l >> c;
    char alp;
    for (int i = 0; i < c; i++) {
        cin >> alp;
        alpha.push_back(alp);
    }

    sort(alpha.begin(), alpha.end());
    vector<char> arr;
    func(0, arr);
    
    return 0;
}