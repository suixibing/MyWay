#include<stdio.h>
#include<stdlib.h>

int main2()
{
	int num[3], i, j, n;
	//求1-999的自幂数(独身数和水仙花数)
	for (n = 1; n < 1000; n++)
	{
		j = n;
		for (i = 0; j != 0; j /= 10)
		{
			num[i] = j % 10;
			i++;
		}
		if (1 == i)
		{
			if (n == num[0])
			{
				printf("%d\n", n);
			}
		}
		else if(2 == i)
		{
			if (n == num[0] * num[0] + num[1] * num[1])
			{
				printf("%d\n", n);
			}
		}
		else if (3 == i)
		{
			if (n == num[0] * num[0] * num[0] + num[1] * num[1] * num[1] + num[2] * num[2] * num[2])
			{
				printf("%d\n", n);
			}
		}
	}

	system("pause");
	return 0;
}
