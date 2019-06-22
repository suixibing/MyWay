#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

char* MyStrcpy(char *dest, char *src)
{
	char *des = dest;

	while (*src != '\0')
	{
		*des++ = *src++;
	}
	*des = '\0';

	return dest;
}

int main1()
{
	char str1[20] = "1234", str2[20] = "abcd";

	MyStrcpy(str1, str2);
	printf("%s\n", str1);

	system("pause");
	return 0;
}