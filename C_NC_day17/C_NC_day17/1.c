#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

char* MyStrncpy(char *dest, char *src, int n)
{
	char *start = dest;

	while (n-- > 0)
	{
		*start++ = *src++;
	}

	return dest;
}

int main1()
{
	char str1[20] = "123456";
	char str2[20] = "abcde";

	MyStrncpy(str1, str2, 3);
	printf("%s\n", str1);

	system("pause");
	return 0;
}