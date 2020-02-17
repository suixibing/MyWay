#include <iostream>
using namespace std;

int main()
{
	int i;
	char pw[101] = { 0 };

	while (scanf("%s", pw) != EOF)
	{
		for (i = 0; pw[i]; ++i)
		{
			if (pw[i] >= 'a' && pw[i] <= 'z')
			{
				if (pw[i] >= 'a' && pw[i] <= 'c')
					pw[i] = '2';
				else if (pw[i] >= 'd' && pw[i] <= 'f')
					pw[i] = '3';
				else if (pw[i] >= 'g' && pw[i] <= 'i')
					pw[i] = '4';
				else if (pw[i] >= 'j' && pw[i] <= 'l')
					pw[i] = '5';
				else if (pw[i] >= 'm' && pw[i] <= 'o')
					pw[i] = '6';
				else if (pw[i] >= 'p' && pw[i] <= 's')
					pw[i] = '7';
				else if (pw[i] >= 't' && pw[i] <= 'v')
					pw[i] = '8';
				else
					pw[i] = '9';
			}
			else if (pw[i] >= 'A' && pw[i] <= 'Y')
				pw[i] = pw[i] - 'A' + 'b';
			else if (pw[i] == 'Z')
				pw[i] = 'a';
		}
		printf("%s\n", pw);
	}

	return 0;
}