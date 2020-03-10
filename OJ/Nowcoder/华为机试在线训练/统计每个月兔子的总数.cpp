#include <iostream>
using namespace std;

int main()
{
	int month, i, n1, n2, n3, tmp;

	while (cin >> month)
	{
		n1 = n2 = 0;
		n3 = 1;
		for (i = 2; i <= month; ++i)
		{
			n1 = n2;
			n2 = n3;
			n3 = n1 + n2;
		}
		cout << n3 << endl;
	}

	return 0;
}