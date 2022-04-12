#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n, m;

        vector<int> v[10001];
        int isVisitA[10001];
        int isVisitB[10001];

        cin >> n >> m;

        memset(isVisitA, -1, sizeof(isVisitA));
        memset(isVisitB, -1, sizeof(isVisitB));

        queue<int> queue_A;
        queue<int> queue_B;

        int a, b;
        cin >> a >> b;
        
        queue_A.push(a);
        queue_B.push(b);

        isVisitA[a] = 1;
        isVisitA[b] = 2;
        isVisitB[a] = 1;
        isVisitB[b] = 2;

        for (int j = 0; j < m; j++) {
            int v1, v2;
            cin >> v1 >> v2;

            v[v1].push_back(v2);
            v[v2].push_back(v1);
        }

        for (int j = 1; j <= n; j++)
            sort(v[j].begin(), v[j].end());

        while (!queue_A.empty() || !queue_B.empty())
        {
            if (!queue_A.empty() && !queue_B.empty())
                if (queue_A.front() == queue_B.front())
                {
                    int fight = queue_A.front();
                    queue_B.pop();
                    queue_A.pop();

                    isVisitA[fight] = 3;
                    isVisitB[fight] = 3;

                    continue;
                }

            if (!queue_A.empty())
            {
                int curA = queue_A.front();

                queue_A.pop();
                if (isVisitB[curA] != 2)
                {
                    isVisitA[curA] = 1;
                    isVisitB[curA] = 1;

                    for (int j = 0; j < v[curA].size(); j++)
                    {
                        if (isVisitA[v[curA][j]] == -1)
                        {
                            isVisitA[v[curA][j]] = 0;
                            queue_A.push(v[curA][j]);
                        }
                    }
                }
            }

            if (!queue_B.empty())
            {
                int curB = queue_B.front();

                queue_B.pop();
                if (isVisitA[curB] != 1)
                {
                    isVisitA[curB] = 2;
                    isVisitB[curB] = 2;

                    for (int i = 0; i < v[curB].size(); i++)
                    {
                        if (isVisitB[v[curB][i]] == -1)
                        {
                            isVisitB[v[curB][i]] = 0;
                            queue_B.push(v[curB][i]);
                        }
                    }
                }
            }
        }

        int half;
        int cnt_fight = 0;
        int cnt_x = 0;
        int cnt_a = 0;
        int cnt_b = 0;

        if (n % 2 == 0)
            half = n / 2;
        else
            half = n / 2 + 1;

        for (int j = 1; j <= n; j++)
        {
            if (isVisitA[j] == 1) cnt_a++;
            else if (isVisitA[j] == 2) cnt_b++;
            else if (isVisitA[j] == 3) cnt_fight++;
            else cnt_x++;
        }

        int success;
        if (half > cnt_a)
            success = half - cnt_a;
        else
            success = 0;

        if (cnt_b < half)
            cout << "#" << i << " " << cnt_fight << " " << success << "\n";
        else
            cout << "#" << i << " " << cnt_fight << " " << -1 << "\n";
    }
    return 0;
}