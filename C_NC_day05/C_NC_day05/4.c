#include<stdio.h>
#include<stdlib.h>

int main4()
{
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			putchar(ch + ('A' - 'a'));
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			putchar(ch - ('A' - 'a'));
		}
		else if (ch == '\n')
		{
			printf("\n\n");
		}
	}

	system("pause");
	return 0;
}