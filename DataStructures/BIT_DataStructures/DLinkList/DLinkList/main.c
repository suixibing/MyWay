#include"DLinkList.h"

void Test_DLinkList()
{
	DList test, *pt = &test;

	DListInit(pt);

	DListPushStart(pt, 3);
	DListPushStart(pt, 6);
	DListPushTail(pt, 2);
	DListPushTail(pt, 9);

	DListPopStart(pt);
	DListPrint(pt);

	DListPushTail(pt, 10);
	DListInsertBefore(DListFind(pt, 2), 99);
	DListPrint(pt);

	DListErase(DListFind(pt, 2));

	DListPopStart(pt);
	DListPrint(pt);

	DListPushTail(pt, 10);
	DListPushTail(pt, 10);
	DListPushTail(pt, 46);
	DListPushTail(pt, 10);
	DListPrint(pt);
	DListRemove(pt, 10);
	DListPrint(pt);

	DListInsertAfter(DListFind(pt, 46), 92);
	DListPrint(pt);

	DListDestory(pt);
}

int main()
{
	Test_DLinkList();

	system("pause");
	return 0;
}