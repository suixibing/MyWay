#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

unsigned int ReverseBit(unsigned int value)
{
	unsigned int i, ret;

	for (i = 0, ret = 0; i < 8 * sizeof(unsigned int); i++)
	{
		ret = 2 * ret + (value & 1);
		value = value >> 1;
	}

	return ret;
}

int main1()
{
	unsigned int n, ret;

	scanf("%d", &n);
	ret = ReverseBit(n);
	printf("%u\n", ret);
	
	system("pause");
	return 0;
}
