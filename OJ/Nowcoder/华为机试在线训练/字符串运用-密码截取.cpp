#include <string>
#include <iostream>
using namespace std;

bool Judge(const string &str, size_t begin, size_t end)
{
	size_t tail = end - 1;
	if (begin == tail)
		return true;
	while (begin < tail)
	{
		if (str[begin] != str[tail])
			return false;
		++begin, --tail;
	}
	return true;
}

int main()
{
	string str;
	size_t i, j;
	bool flag;

	while (cin >> str)
	{
		flag = 0;
		for (i = str.size(); i > 0; --i)
		{
			for (j = 0; j + i <= str.size(); ++j)
			{
				if (Judge(str, j, j + i))
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}