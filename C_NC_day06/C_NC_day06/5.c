#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int IsPrime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int input;

	scanf("%d", &input);
	if (IsPrime(input))
	{
		printf("%d是素数\n", input);
	}
	else
	{
		printf("%d不是素数\n", input);
	}

	system("pause");
	return 0;
}