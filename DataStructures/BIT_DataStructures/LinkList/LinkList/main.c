#include"LinkList.h"

void Test_LinkList()
{
	SList test, *pt = &test;
	SList test2, *pt2 = &test2;
	SListNode *tmp1, *tmp2;

	SListInit(pt);
	SListInit(pt2);

	SListPushFront(pt, 4);
	SListPushFront(pt, 3);
	SListPushFront(pt, 1);
	SListPushFront(pt, 2);
	SListPushFront(pt, 9);
	SListPushFront(pt, 4);
	SListPushFront(pt, 1);
	SListPrint(pt);
	SListPopFront(pt);
	SListPrint(pt);
	SListPopFront(pt);
	SListPrint(pt);

	SListReverse(pt);
	SListPrint(pt);

	SListInsertAfter(SListFind(pt, 3), 0);
	SListPrint(pt);

	SListInsertFront(pt, SListFind(pt, 3), 0);
	SListPrint(pt);

	SListEraseAfter(SListFind(pt, 3));
	SListPrint(pt);

	SListRemove(pt, 0);
	SListPrint(pt);

	//tmp1 = SListFind(pt, 3);
	//tmp1 = pt->_head;
	//tmp2 = SListFind(pt, 9);
	//tmp2->_next = tmp1;
	if (SListHasCycle(pt) > 0)
	{
		printf("yes\n");
		printf("%d\n", (SListDetectCycle(pt))->_data);
	}
	else
		printf("no\n");

	SListReverse(pt);
	//SListPrint(pt);
	SListPrint(pt2);

	//if (GetIntersectionNode(pt, pt2))
	//{
	//	SListPrint(GetIntersectionNode(pt, pt2));
	//}
	//else
	//{
	//	printf("δ�ཻ!\n");
	//}
	

	SListDestory(pt);
	SListDestory(pt2);
}

int main()
{
	Test_LinkList();

	system("pause");
	return 0;
}