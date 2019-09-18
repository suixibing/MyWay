#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int CmpBits(int value1, int value2)
{
	int i, tmp1, tmp2, count;

	for (i = 0, count = 0; i < 8 * sizeof(int); i++)
	{
		tmp1 = value1 & (1 << i);
		tmp2 = value2 & (1 << i);
		if (tmp1 != tmp2)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int n1, n2, ret;

	scanf("%d%d", &n1, &n2);
	ret = CmpBits(n1, n2);
	printf("%d\n", ret);
	
	system("pause");
	return 0;
}
