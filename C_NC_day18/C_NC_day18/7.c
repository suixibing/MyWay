#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void* MyMemmove(void *a, void *b, int size)
{
	char *tmp;
	char *p = (char*)a;
	char *q = (char*)b;

	if (p < q || p > q + size)
	{
		tmp = p;
		while (size-- > 0)
		{
			*tmp++ = *q++;
		}
	}
	else
	{
		tmp = p + size - 1;
		q = q + size - 1;
		while (tmp > p)
		{
			*tmp-- = *q--;
		}
		*tmp = *q;
	}

	return a;
}

int main()
{
	char str1[20] = "1234", str2[20] = "12754", *pc = NULL;
	int i, a[100] = { 0 };
	int b[100] = { 1,23,45,53,3 };

	MyMemmove(str1, str2, sizeof(str2));
	printf("%s\n", str1);
	MyMemmove(a, b, sizeof(b));
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	system("pause");
	return 0;
}