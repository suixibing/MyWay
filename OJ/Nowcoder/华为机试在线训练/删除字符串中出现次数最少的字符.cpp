#include <iostream>
using namespace std;

int main()
{
	int i, size, minNum;
	string str;

	while (cin >> str)
	{
		char book[26] = { 0 };
		size = str.size();
		for (i = 0; i < size; ++i)
			++book[str[i] - 'a'];
		for (i = 1, minNum = book[str[0] - 'a']; i < size; ++i)
		{
			if (book[str[i] - 'a'] < minNum)
				minNum = book[str[i] - 'a'];
		}
		for (i = 0; i < size; ++i)
		{
			if (book[str[i] - 'a'] > minNum)
				putchar(str[i]);
		}
		putchar('\n');
	}

	return 0;
}