#include <iostream>
using namespace std;

int main()
{
    int i, n, tmp, flag, *data;
    
    while (cin >> n)
    {
        flag = 0;
        data = new int[n];
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &tmp);
            data[tmp - 1] = 1;
            if (tmp - 1 == flag)
            {
                while (flag <= n && data[flag])
                    printf("%d %d\n", ++flag, tmp);
            }
        }
        delete []data;
    }
    
    return 0;
}