#include"DataStructures.h"

void LinkListTest_2()
{
	int input, count, head = -1, len = -1;
	S_NODE slist[100];

	while (1)
	{
		scanf("%d", &input);
		if (input == END)
		{
			break;
		}
		len++;
		slist[len].data = input;
		slist[len].next = -1;
		if (len == 0)
		{
			head = 0;
			continue;
		}
		count = head;
		if (slist[head].data > slist[len].data)
		{
			slist[len].next = head;
			head = len;
			continue;
		}
		while (slist[count].next != -1 && slist[slist[count].next].data < slist[len].data)
		{
			count = slist[count].next;
		}
		slist[len].next = slist[count].next;
		slist[count].next = len;
	}
	if (head == -1)
	{
		printf("Пе\n");
		return;
	}
	count = head;
	while (slist[count].next != -1)
	{
		printf("%d -> ", slist[count].data);
		count = slist[count].next;
	}
	printf("%d\n", slist[count].data);
}