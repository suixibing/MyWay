#include<stdio.h>
#include<stdlib.h>
//判断1000年---2000年之间的闰年
int main()
{
	int year;
	for (year = 1000; year <= 2000; year += 4)
	{
		//能被100和400同时整除的年份也为闰年
		if (year % 100 == 0 && year % 400 != 0)
		{
			continue;
		}
		printf("%d\n", year);
	}
	system("pause");
	return 0;
}