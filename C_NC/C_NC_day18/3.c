#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

char* MyStrstr(char *str1, char *str2)
{
	char *p, *q, *start;

	for (start = str1, p = start, q = str2; *p != '\0' && *q != '\0'; )
	{
		if (*p != *q)
		{
			q = str2;
			start++;
			p = start;
			continue;
		}
		q++;
		p++;
	}
	if (*q == '\0')
	{
		return start;
	}

	return NULL;
}

int main3()
{
	char str1[20] = "1234", str2[20] = "23", *pc = NULL;

	pc = MyStrstr(str1, str2);
	if (pc != NULL)
	{
		printf("%s\n", pc);
	}
	else
	{
		printf("√ª”–’“µΩ£°\n");
	}

	system("pause");
	return 0;
}