#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//打印100~200之间的素数 
int main1()
{
	int num, i;
	for (num = 100; num <= 200; num++)
	{
		for (i = 2; i <= sqrt(num); i++)
		{
			//如果有能整除的数，则不是素数
			if (num%i == 0)
			{
				break;
			}
		}
		//判断内层循环是否正常结束
		if (i <= sqrt(num))
		{
			continue;
		}
		else
		{
			printf("%d\n", num);
		}
	}
	system("pause");
	return 0;
}