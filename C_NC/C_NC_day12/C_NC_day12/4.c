#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void Reverse(char *str, int start, int end)
{
	char tmp;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

int main4()
{
	char str[] = "student a am I";
	int i, start = 0, end;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			end = i - 1;
			Reverse(str, start, end);
			start = i + 1;
		}
	}
	Reverse(str, 0, i - 1);
	printf("%s\n", str);
	
	system("pause");
	return 0;
}
