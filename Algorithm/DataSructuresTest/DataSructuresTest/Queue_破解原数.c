#include"DataStructures.h"

void QueueTest_1()
{
	QUEUE q;
	int i, len, arr[] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 };

	len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < len; i++)
	{
		q.arr[i] = arr[i];
	}
	q.head = 0;
	q.tail = len;
	i = 0;
	while (q.head < q.tail)
	{
		arr[i] = q.arr[q.head];
		i++;
		q.head++;

		q.arr[q.tail] = q.arr[q.head];
		q.tail++;
		q.head++;
	}
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}