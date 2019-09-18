#include"DataStructures.h"

void LinkListTest_1()
{
	int input;
	LIST head = NULL;
	NODE *p, *tmp;

	while (1)
	{
		scanf("%d", &input);
		if (input == END)
		{
			break;
		}
		p = (NODE*)malloc(sizeof(NODE));
		if (p == NULL)
		{
			break;
		}
		p->data = input;
		if (head == NULL)
		{
			head = (NODE*)malloc(sizeof(NODE));
			head->next = p;
			p->next = NULL;
		}
		else
		{
			tmp = head;
			while (tmp->next != NULL && tmp->next->data < p->data)
			{
				tmp = tmp->next;
			}
			p->next = tmp->next;
			tmp->next = p;
		}
	}
	if (head == NULL)
	{
		return;
	}
	tmp = head->next;
	while (tmp != NULL)
	{
		printf("%d", tmp->data);
		tmp = tmp->next;
		if (tmp != NULL)
		{
			printf(" -> ");
		}
	}
	putchar('\n');
}