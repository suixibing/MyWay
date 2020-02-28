#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		for (int i = 1, first = 1; i <= n; ++i)
		{
			cout << first;
			int tmp = first;
			for (int j = i + 1; j <= n; ++j)
			{
				tmp += j;
				cout << ' ' << tmp;
			}
			cout << endl;
			first += i;
		}
	}

	return 0;
}