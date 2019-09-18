#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void* MyMemcpy(void *a, void *b, int size)
{
	char *p = (char*)a;
	char *q = (char*)b;

	while (size-- > 0)
	{
		*p++ = *q++;
	}

	return a;
}

int main6()
{
	char str1[20] = "1234", str2[20] = "12754", *pc = NULL;
	int i, a[10] = { 0 };
	int b[5] = { 1,23,45,53,3 };

	MyMemcpy(str1, str2, sizeof(str2));
	printf("%s\n", str1);
	MyMemcpy(a, b, sizeof(a));
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	system("pause");
	return 0;
}
