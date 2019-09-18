#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main2()
{
	int x;

	for (x = 1; x <= 4; x++)
	{
		if ((x != 1) + (x == 3) + (x == 4) + (x != 4) == 3)
		{
			printf("%cÊÇÐ×ÊÖ\n", x + 'A' - 1);
		}
	}

	system("pause");
	return 0;
}
