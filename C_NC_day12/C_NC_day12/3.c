#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define N 11

int main3()
{
	int a[N];
	int i, tmp = 0;

	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		tmp = tmp ^ a[i];
	}
	printf("%d\n", tmp);
	
	system("pause");
	return 0;
}
