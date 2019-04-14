#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	int i, count;

	for (i = 0, count = 0; i < 8 * sizeof(value); i++)
	{
		if ((value & 1 << i) == 1 << i)
		{
			count++;
		}
	}

	return count;
}

int main1()
{
	int ret;

	ret = count_one_bits(15);
	printf("%d\n", ret);

	system("pause");
	return 0;
}

