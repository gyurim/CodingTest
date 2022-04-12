#include <iostream>
using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;

    long long high = 1000000000;
    long long low = 0;

    long long z = y * 100 / x;
    long long mid = -1;

    if (z >= 99) // 1패라도 있으면 승률은 100%가 될 수 없다. 
        cout << -1;
    else
    {
        while (low < high)
        {

            mid = (low + high) / 2;

            long long ug = y + mid; // update grade
            long long ut = x + mid; // update total
            long long uz = ug * 100 / ut;

            if (uz > z)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << low;
    }

    return 0;
}