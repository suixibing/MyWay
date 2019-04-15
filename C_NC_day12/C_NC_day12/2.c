#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main2()
{
	double a, b, ave;

	scanf("%lf%lf", &a, &b);
	ave = a + (b - a) / 2;
	printf("average = %f\n", ave);
	
	system("pause");
	return 0;
}
