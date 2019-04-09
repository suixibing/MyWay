#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int Judge(int a, int b, int c, int d, int e)
{
	int i = 0;

	i |= 1 << a;
	i |= 1 << b;
	i |= 1 << c;
	i |= 1 << d;
	i |= 1 << e;
	
	if (i == 62)
	{
		return 1;
	}
	return 0;
}

int main1()
{
	int a, b, c, d, e;

	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (Judge(a, b, c, d, e) && 
							(b == 2) + (a == 3) == 1 && 
							(b == 2) + (e == 4) == 1 && 
							(c == 1) + (d == 2) == 1 && 
							(c == 5) + (d == 3) == 1 && 
							(e == 4) + (a == 1) == 1)
						{
							printf("A 第%d名，B 第%d名，C 第%d名，D 第%d名，E 第%d名 \n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}
