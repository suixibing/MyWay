#include"LinkList.h"

void Test_LinkList()
{
	SList test, *pt = &test;

	SListInit(pt);

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

	SListInsertAfter(SListFind(pt, 3), 0);
	SListPrint(pt);

	SListInsertFront(pt, SListFind(pt, 3), 0);
	SListPrint(pt);

	SListEraseAfter(SListFind(pt, 3));
	SListPrint(pt);

	SListRemove(pt, 0);
	SListPrint(pt);

	SListDestory(pt);
}

int main()
{
	Test_LinkList();


	system("pause");
	return 0;
}