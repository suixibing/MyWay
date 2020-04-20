#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x, y, z, tmp;
    
    while (cin >> x >> y >> z)
    {
        vector<vector<int> > mat1(x, vector<int>(y));
        vector<vector<int> > mat2(y, vector<int>(z));
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
                cin >> mat1[i][j];
        }
        for (int i = 0; i < y; ++i)
        {
            for (int j = 0; j < z; ++j)
                cin >> mat2[i][j];
        }
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < z; ++j)
            {
                tmp = 0;
                for (int k = 0; k < y; ++k)
                    tmp += mat1[i][k] * mat2[k][j];
                if (j != 0)
                    cout << " ";
                cout << tmp;
            }
            cout << endl;
        }
    }
    
    return 0;
}