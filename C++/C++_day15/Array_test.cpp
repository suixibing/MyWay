#include "MyArray.h"
using namespace std;
using namespace lb;

int main()
{
	int *p;
	{
		Array<int> a, b(5);

		for (int i = 0; i < 5; ++i)
			b[i] = i + 1;
		for (int i = 0; i < 5; ++i)
			cout << b[i] << " ";
		p = &b[2];
		cout << "p = " << *p << endl;
	}
	cout << "p = " << *p << endl;

	return 0;
}