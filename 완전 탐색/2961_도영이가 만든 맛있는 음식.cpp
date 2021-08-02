#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int a[11];
int b[11];

long long getFlavor(int pos, long long sour, long long bit, int cnt) {
    cout << "pos: " << pos << " / sour: " << sour << " / bit: " << bit << " / cnt: " << cnt << endl;
    if (pos == N) {
        if (cnt == 0) return 9999999999; // 적어도 하나의 재료는 사용해야함
        return abs(sour-bit);
    } else 
        return min(
            getFlavor(pos + 1, sour * a[pos+1], bit + b[pos+1], cnt + 1), 
            getFlavor(pos + 1, sour, bit, cnt)
        );
}

int main() { 
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    cout << getFlavor(0, 1, 0, 0);
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     // 신맛과 쓴맛의 차이가 가장 작은 요리 
//     vector<pair<long long, long long>> ingredient;

//     for (int i = 0; i < n; i++) {
//         long long si, bi;
//         cin >> si >> bi;
//         ingredient.push_back(make_pair(si, bi));
//     }

//     // 요리는 재료 1개 이상 
//     long long minimum = -1;

//     for (int i = 1; i <= n; i++) {
//         vector<int> isflag;
//         for (int j = 0; j < n; j++) {
//             if (j < i) isflag.push_back(0);
//             else isflag.push_back(1);
//         }

//         do {
//             long long s_flavor = -1;
//             long long b_flavor = 0;

//             for (int i = 0; i < n; i++) {
//                 if (isflag[i] == 0) { // 선택된 ingredient
//                     if (s_flavor == -1) s_flavor = ingredient[i].first;
//                     else s_flavor *= ingredient[i].first;
                    
//                     b_flavor += ingredient[i].second;
//                     // cout << s_flavor << " " << b_flavor << endl;
//                 }
//             }

//             long long differ = llabs(s_flavor - b_flavor);

//             if (minimum == -1) minimum = differ;
//             else {
//                 minimum = (minimum >= differ) ? differ : minimum;
//             }
//         } while (next_permutation(isflag.begin(), isflag.end()));
//     }
//     cout << minimum;
//     return 0;
// }