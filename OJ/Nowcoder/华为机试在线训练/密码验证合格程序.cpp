#include <bitset>
#include <string>
#include <iostream>
using namespace std;

bool judgePW(const char *pw)
{
	bitset<4> book;

	for (int i = 0; pw[i]; ++i)
	{
		if (pw[i] >= '0' && pw[i] <= '9')
			book.set(0);
		else if (pw[i] >= 'a' && pw[i] <= 'z')
			book.set(1);
		else if (pw[i] >= 'A' && pw[i] <= 'Z')
			book.set(2);
		else
			book.set(3);
		for (int j = i + 1; pw[j] && pw[j + 1] && pw[j + 2]; ++j)
			if (pw[i] == pw[j] && pw[i + 1] && pw[i + 1] == pw[j + 1]
				&& pw[i + 2] && pw[i + 2] == pw[j + 2])
				return false;
	}
	return book.count() >= 3;
}

int main()
{
	string pw;

	while (cin >> pw)
	{
		if (pw.size() > 8 && judgePW(pw.c_str()))
			printf("OK\n");
		else
			printf("NG\n");
	}

	return 0;
}