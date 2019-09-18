#include<stdio.h>
#include<stdlib.h>

int main2()
{
	int i;
	float num = 0, flag = 1.0;

	for (i = 1; i <= 100; i++)
	{
		num += flag/i;
		flag = -flag;
	}
	printf("1/1-1/2+1/3-1/4+...+1/99-1/100 = %f\n", num);

	system("pause");
	return 0;
}