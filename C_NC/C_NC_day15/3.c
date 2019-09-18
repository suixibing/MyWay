#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void MyStrcpy(char *str1, char *str2)
{
	while (*str2 != '\0')
	{
		*str1++ = *str2++;
	}
}

int main3()
{
	char str1[20] = { 0 }, str2[20] = { 0 };

	scanf("%s", str2);
	MyStrcpy(str1, str2);
	printf("%s\n", str1);

	system("pause");
	return 0;
}
