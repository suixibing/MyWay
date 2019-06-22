#include"SeqList.h"

int main()
{
	int ret;
	SeqList test;

	SeqListInit(&test, 10);

	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPopBack(&test);
	SeqListPushBack(&test, 4);
	SeqListPushFront(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushFront(&test, 7);
	SeqListPushBack(&test, 8);
	SeqListPopFront(&test);

	SeqListPrint(&test);

	SeqListInsert(&test, 3, 19);
	ret = SeqListFind(&test, 6);
	SeqListRemove(&test, 8);
	SeqListModify(&test, 3, 17);

	SeqListPrint(&test);

	SeqListDestory(&test);
	system("pause");
	return 0;
}