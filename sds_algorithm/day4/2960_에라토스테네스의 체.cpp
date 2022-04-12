#include <iostream>
using namespace std;

// memset으로 초기화했다가 안돼서 삽질함. 0, -1 제외 fill_n으로 초기화해야됨 

int main()
{
    int n, k;
    bool primes[1005];
    cin >> n >> k;
    
    fill_n(primes, n+1, true);
    primes[1] = false;

    int cnt = 0;

    for (int i = 2; i <= n; i++)
    {
        bool isEnd = false;
        if (primes[i])
        {
            for (int j = 1; j * i <= n; j++)
            {
                if (!primes[i*j])
                    continue;

                primes[j * i] = false;
                cnt++;

                if (cnt == k)
                {
                    cout << j * i;
                    isEnd = true;
                    break;
                }
            } 
        }

        if (isEnd) break;
    }
    return 0;
}