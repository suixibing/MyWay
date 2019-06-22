#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int DigitSum(int n)
{
	int sum = 0;
	if (n > 9)
	{
		sum += n % 10 + DigitSum(n / 10);
	}
	else
	{
		sum = n;
	}
	return sum;
}

int main3()
{
	int input, ret;
	scanf("%d", &input);
	ret = DigitSum(input);
	printf("%d\n", ret);

	system("pause");
	return 0;
}
