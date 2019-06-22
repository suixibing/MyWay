#include<stdio.h>
#include<stdlib.h>

int main5()
{
	int num1 = 45, num2 = 75, tmp;
	if (num1 < num2)
	{
		tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	//Õ·×ªÏà¼õ·¨
	while (num2 != 0)
	{
		tmp = num1 - num2;
		num1 = num2;
		num2 = tmp;
	}
	printf("%d\n", num1);
	system("pause");
	return 0;
}

//a		b	tmp
//45	75	30
//45	30	15
//30	15	15
//15	15	0
//15	0	