#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int MyStrncmp(char *dest, char *src, int n)
{
	char *start = dest;

	while (n-- > 0)
	{
		if (*start != *src)
		{
			return *start - *src;
		}
		start++;
		src++;
	}

	return 0;
}

int main()
{
	char str1[20] = "123456";
	char str2[20] = "12345";

	printf("%d\n", MyStrncmp(str1, str2, 6));

	system("pause");
	return 0;
}