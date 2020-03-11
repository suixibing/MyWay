#include <iostream>
using namespace std;

int main()
{
	double height, sum, tmp;

	while (cin >> height)
	{
		sum = height;
		for (size_t i = 0; i < 4; ++i)
		{
			sum += height;
			height /= 2;
		}
		cout << sum << endl << height / 2 << endl;
	}

	return 0;
}