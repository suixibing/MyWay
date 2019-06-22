#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ReverseString1(char *pstr)
{
	char tmp;
	int i = 0;
	if (*(pstr + 1) != '\0')
	{
		tmp = *pstr;
		ReverseString1(pstr + 1);
		for (i = 0; *(pstr + i + 1) != '\0'; i++)
		{
			*(pstr + i) = *(pstr + i + 1);
		}
		*(pstr + i) = tmp;
	}

	return *pstr;
}

void ReverseString2(char *pstr)
{
	char tmp;
	int len = strlen(pstr);
	tmp = *pstr;
	*pstr = *(pstr + len - 1);
	*(pstr + len - 1) = '\0';
	if (*(pstr + 1) != '\0')
	{
		ReverseString2(pstr + 1);
	}
	*(pstr + len - 1) = tmp;
}

int main4()
{
	char string[] = "China";
	char *pstr = string;

	ReverseString1(pstr);
	ReverseString2(pstr);
	printf("%s\n", string);
	system("pause");
	return 0;
}
