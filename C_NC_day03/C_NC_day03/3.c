#include<stdio.h>
#include<stdlib.h>

int main3()
{
	int i, score = 0;

	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			score++;
		}
		if (i / 10 == 9)
		{
			score++;
		}
	}
	printf("数字9共出现%d次\n",score);
	
	system("pause");
	return 0;
}
