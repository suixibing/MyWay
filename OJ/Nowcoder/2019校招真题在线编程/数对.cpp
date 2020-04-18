#include <iostream>
using namespace std;

int main()
{
    long long i, n, k, cnt;
    
    while (cin >> n >> k)
    {
        cnt = 0;
        if (k == 0)
            cnt = n * n;
        else
        {
            for (i = k + 1; i <= n; ++i)
            {
                cnt += (n / i) * (i - k);
                cnt += (n % i - k >= 0) ? n % i - k + 1 : 0;
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}