#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, max, cnt;
    
    while (cin >> n)
    {
        vector< vector<int> > point(4, vector<int>(n));
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < n; ++j)
                cin >> point[i][j];
        }
        max = cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cnt = 0;
                for (int k = 0; k < n; ++k)
                {
                    if (point[0][i] >= point[0][k] && point[0][i] < point[2][k]
                       && point[1][j] >= point[1][k] && point[1][j] < point[3][k])
                        ++cnt;
                }
                if (cnt > max)
                    max = cnt;
            }
        }
        cout << max << endl;
    }
    
    return 0;
}