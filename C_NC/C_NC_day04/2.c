#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int i, j, n, sum, num[10];
	for (i = 0; i < 1000000; i++)
	{
		for (n = 0, j = i; j; j /= 10)
		{
			num[n] = j % 10;
			n++;
		}
		for (sum = 0, j = 0; j < n; j++)
		{
			sum += pow(num[j], n);
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}

	system("pause");
	return 0;
}

//
//int main2()
//{
//	int num[5], i, j, n;
//	//求0-999的自幂数(独身数和水仙花数)
//	for (n = 0; n < 1000; n++)
//	{
//		j = n;
//		for (i = 0; j != 0; j /= 10)
//		{
//			num[i] = j % 10;
//			i++;
//		}
//		if (1 == i)
//		{
//			if (n == num[0])
//			{
//				printf("%d\n", n);
//			}
//		}
//		else if(2 == i)
//		{
//			if (n == num[0] * num[0] + num[1] * num[1])
//			{
//				printf("%d\n", n);
//			}
//		}
//		else if (3 == i)
//		{
//			if (n == num[0] * num[0] * num[0] + num[1] * num[1] * num[1] + num[2] * num[2] * num[2])
//			{
//				printf("%d\n", n);
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}
