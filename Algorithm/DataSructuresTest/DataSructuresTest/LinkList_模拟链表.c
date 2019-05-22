#include"DataStructures.h"

void LinkListTest_2()
{
	int input, count, head = 0, len = -1;
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
		count = head;
		while (slist[count].data > slist[len].data || (slist[count].next != -1 && slist[slist[count].next].data < slist[len].data))
		{
			count = slist[count].next;
		}
		slist[len].next = slist[count].next;
		if (len == 0)
		{
			continue;
		}
		slist[count].next = len;
	}
	count = head;
	while (slist[count].next != -1)
	{
		printf("%d -> ", slist[count].data);
		count = slist[count].next;
	}
	printf("%d\n", slist[count].data);
}