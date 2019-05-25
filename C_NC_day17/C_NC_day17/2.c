#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

char* MyStrncat(char *dest, char *src, int n)
{
	char *start = dest;
	
	while (*start)
	{
		start++;
	}
	while (n-- > 0)
	{
		*start++ = *src++;
	}
	*start = '\0';

	return dest;
}

int main2()
{
	char str1[20] = "123456";
	char str2[20] = "abcde";

	MyStrncat(str1, str2, 3);
	printf("%s\n", str1);

	system("pause");
	return 0;
}