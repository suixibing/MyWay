#include"DataStructures.h"

void StackTest1()
{
	int i, len;
	char input[100];
	STACK s;

	s.top = -1;
	scanf("%s", input);
	len = strlen(input);
	for (i = 0; i < len / 2; i++)
	{
		s.top++;
		s.arr[s.top] = input[i];
	}
	if (len % 2)
	{
		i++;
	}
	while (i < len)
	{
		if (s.arr[s.top] != input[i])
		{
			break;
		}
		s.top--;
		i++;
	}
	if (i < len)
	{
		printf("不是回文\n");
	}
	else
	{
		printf("是回文\n");
	}
}