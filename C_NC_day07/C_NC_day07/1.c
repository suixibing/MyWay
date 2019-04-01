#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//·ÇµÝ¹é
int Fibo1(int n)
{
	int first = 1;
	int second = 1;
	int third = 1;
	while (n > 2)
	{
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return second;
}
//µÝ¹é
int Fibo2(int n)
{
	if (n > 2)
	{
		return Fibo2(n - 1) + Fibo2(n - 2);
	}
	else
	{
		return 1;
	}
}

int main1()
{
	int input;
	int ret;
	scanf("%d", &input);
	ret = Fibo1(input);
	printf("%d\n", ret);

	system("pause");
	return 0;
}