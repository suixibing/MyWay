#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

char* MyStrchr(char *str1, char ch)
{
	char *start;

	for (start = str1; *start != '\0'; start++)
	{
		if (*start == ch)
		{
			return start;
		}
	}

	return NULL;
}

int main4()
{
	char str1[20] = "1234", ch = '3', *pc = NULL;

	pc = MyStrchr(str1, ch);
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