#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *p, *tmp, str[] = "student a am I";

	tmp = (char*)calloc(sizeof(str) / sizeof(char), sizeof(char));
	if (tmp != NULL)
	{
		while (p = strrchr(str, ' '))
		{
			strcat(tmp, p + 1);
			strcat(tmp, " ");
			*p = '\0';
		}
		strcat(tmp, str);
		strcpy(str, tmp);
		printf("%s\n", str);
		free(tmp);
	}
	
	system("pause");
	return 0;
}