#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void MyStrcat(char *str1, char *str2)
{
	while (*str1 != '\0')
	{
		str1++;
	}
	while (*str2 != '\0')
	{
		*str1++ = *str2++;
	}
}

int main()
{
	char str1[20] = { 0 }, str2[20] = { 0 };

	scanf("%s%s", str1, str2);
	MyStrcat(str1, str2);
	printf("%s\n", str1);

	system("pause");
	return 0;
}
