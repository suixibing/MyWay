#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int MyStrlen1(char *p)
{
	int len = 0;
	while (*(p + len) != '\0')
	{
		len++;
	}
	return len;
}

int MyStrlen2(char *p)
{
	int len = 1;
	if (*(p + 1) != '\0')
	{
		len = MyStrlen2(p + 1) + 1;
	}
	return len;
}

int main5()
{
	char *pstr = "alkjdfls";
	int len = MyStrlen2(pstr);

	printf("%d\n", len);
	system("pause");
	return 0;
}
