#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1005];
int b[1005];
int as[1005] = {0};
int bs[1005] = {0};

vector<int> partA;
vector<int> partB;

long long t;
int n, m;

// 투포인터
// 누적합 -> Prefix Sum

// 시간 초과 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> t;

    if (t <= 0)
        cout << "0";
    else
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            as[i] = as[i - 1] + a[i];
        }

        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
            bs[i] = bs[i - 1] + b[i];
        }

        // 부분 집합 저장 및 정렬
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                partA.push_back(as[j] - as[i]);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j <= m; j++)
            {
                partB.push_back(bs[j] - bs[i]);
            }
        }
        sort(partA.begin(), partA.end());
        sort(partB.begin(), partB.end());

        // binary search 이용해 횟수 찾기 
        int a_idx = lower_bound(partA.begin(), partA.end(), t) - partA.begin();
        int b_idx = lower_bound(partB.begin(), partB.end(), t) - partB.begin();
        
        int nextJ = 0;
        int cnt = 0;
        
        for (int i = a_idx; i >= 0; i--) {
            if (partA[i] == t) continue;
            for (int j = nextJ; j <= b_idx; j++) {
                if (partA[i] + partB[j] == t) {
                    cnt++;
                    nextJ = j;
                } else if (partA[i] + partB[j] > n) {
                    break;
                }
            }
        }
        cout << cnt;
    }

    return 0;
}