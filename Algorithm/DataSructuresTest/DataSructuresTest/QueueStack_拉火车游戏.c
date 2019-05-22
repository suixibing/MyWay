#include"DataStructures.h"
#define N 6

void QueueStackTest_1()
{
	int i, tmp, book[20] = { 0 };
	STACK s;
	QUEUE q1, q2;

	q1.head = 0;
	q1.tail = 0;
	q2.head = 0;
	q2.tail = 0;
	s.top = -1;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &q1.arr[q1.tail]);
		q1.tail++;
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d", &q2.arr[q2.tail]);
		q2.tail++;
	}
	while (q1.head < q1.tail && q2.head < q2.tail)
	{
	q1:
		tmp = q1.arr[q1.head];
		q1.head++;
		if (book[tmp] == 0)
		{
			s.top++;
			s.arr[s.top] = tmp;
			book[tmp] = 1;
		}
		else
		{
			q1.arr[q1.tail] = tmp;
			book[tmp] = 0;
			q1.tail++;
			while (s.arr[s.top] != tmp)
			{
				q1.arr[q1.tail] = s.arr[s.top];
				book[s.arr[s.top]] = 0;
				s.top--;
				q1.tail++;
			}
			q1.arr[q1.tail] = tmp;
			s.top--;
			q1.tail++;
			goto q1;
		}
	q2:
		tmp = q2.arr[q2.head];
		q2.head++;
		if (book[tmp] == 0)
		{
			s.top++;
			s.arr[s.top] = tmp;
			book[tmp] = 1;
		}
		else
		{
			q2.arr[q2.tail] = tmp;
			book[tmp] = 0;
			q2.tail++;
			while (s.arr[s.top] != tmp)
			{
				q2.arr[q2.tail] = s.arr[s.top];
				book[s.arr[s.top]] = 0;
				s.top--;
				q2.tail++;
			}
			q2.arr[q2.tail] = tmp;
			s.top--;
			q2.tail++;
			goto q2;
		}
#if 0
		printf("\n[q1.arr]");
		for (int j = q1.head; j < q1.tail; j++)
		{
			printf("%d ", q1.arr[j]);
		}
		printf("        [q2.arr]");
		for (int j = q2.head; j < q2.tail; j++)
		{
			printf("%d ", q2.arr[j]);
		}
		printf("        [s.arr]");
		for (int j = 0; j <= s.top; j++)
		{
			printf("%d ", s.arr[j]);
		}
#endif
	}
	if (s.top != -1)
	{
		printf("\n桌面上剩余的牌有：");
		for (i = 0; i <= s.top; i++)
		{
			printf("%c ", s.arr[i] + '0');
		}
	}
	if (q1.head < q1.tail)
	{
		printf("\n甲胜利，手上剩余的牌有：");
		while (q1.head < q1.tail)
		{
			printf("%d ", q1.arr[q1.head]);
			q1.head++;
		}
	}
	else
	{
		printf("\n乙胜利，手上剩余的牌有：");
		while (q2.head < q2.tail)
		{
			printf("%d ", q2.arr[q2.head]);
			q2.head++;
		}
	}
	putchar('\n');
}