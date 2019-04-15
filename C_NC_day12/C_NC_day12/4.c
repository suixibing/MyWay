#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char tmp, str[] = "student a am i";
	int i, j, k, n = 0;

	while (str[n] != '\0')
	{
		n++;
	}
	for (i = 0; i < n / 2; i++)
	{
		tmp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = tmp;
	}
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
		{
			//用j标记单词间的空格
		}
		while (i < j - k / 2)
		{
			tmp = str[i];
			str[i] = str[j + k - i - 1];
			str[j + k - i - 1] = tmp;
			i++;
		}
		i = j;
	}

	printf("%s\n", str);
	
	system("pause");
	return 0;
}
