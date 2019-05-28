#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int MyStrcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return *str1 - *str2;
		}
		str1++;
		str2++;
	}
	
	return 0;
}

int main5()
{
	char str1[20] = "1234", str2[20] = "12754", *pc = NULL;

	if (!MyStrcmp(str1, str2))
	{
		printf("字符串相同\n");
	}
	else
	{
		printf("不同！\n");
	}

	system("pause");
	return 0;
}
