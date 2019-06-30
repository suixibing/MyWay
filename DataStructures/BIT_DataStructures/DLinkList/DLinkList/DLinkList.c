#include"DLinkList.h"

void DListInit(DList* plist)
{
	assert(plist);

	plist->_head = (DListNode*)malloc(sizeof(DListNode));

	assert(plist->_head);

	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void DListDestory(DList* plist)
{
	assert(plist);

	DListNode *tmp;
	DListNode *cur = plist->_head->_next;

	while (cur != plist->_head)
	{
		tmp = cur;
		cur = cur->_next;
		cur->_prev = tmp->_prev;
		free(tmp);
	}
}

void DListPushStart(DList* plist, LTDataType x)
{
	assert(plist);

	DListNode *cur = (DListNode*)malloc(sizeof(DListNode));

	assert(cur);

	cur->_data = x;
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
	cur->_next->_prev = cur;
}
void DListPopStart(DList* plist)
{
	assert(plist);

	DListNode *cur;

	if (plist->_head->_next != plist->_head)
	{
		cur = plist->_head->_next;
		plist->_head->_next = cur->_next;
		cur->_next->_prev = plist->_head;
		free(cur);
	}
}
void DListPushTail(DList* plist, LTDataType x)
{
	assert(plist);

	DListNode *cur = (DListNode*)malloc(sizeof(DListNode));

	assert(cur);

	cur->_data = x;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;
	cur->_next = plist->_head;
	cur->_prev->_next = cur;
}
void DListPopTail(DList* plist)
{
	assert(plist);

	DListNode *cur;

	if (plist->_head->_prev != plist->_head)
	{
		cur = plist->_head->_prev;
		plist->_head->_prev = cur->_prev;
		cur->_prev->_next = plist->_head;
		free(cur);
	}
}

DListNode* DListFind(DList* plist, LTDataType x)
{
	assert(plist);

	DListNode *cur;

	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}

	return NULL;
}
// 在pos的前面进行插入 
void DListInsertBefore(DListNode* pos, LTDataType x)
{
	assert(pos);

	DListNode *cur = (DListNode*)malloc(sizeof(DListNode));

	assert(cur);

	cur->_data = x;
	cur->_prev = pos->_prev;
	pos->_prev = cur;
	cur->_next = pos;
	cur->_prev->_next = cur;
}
// 在pos的后面进行插入 
void DListInsertAfter(DListNode* pos, LTDataType x)
{
	assert(pos);

	DListNode *cur = (DListNode*)malloc(sizeof(DListNode));

	assert(cur);

	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
	cur->_prev = pos;
	cur->_next->_prev = cur;
}
// 删除pos位置的节点 
void DListErase(DListNode* pos)
{
	assert(pos);

	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;
	free(pos);
}
void DListRemove(DList* plist, LTDataType x)
{
	assert(plist);

	DListNode *cur;

	while (cur = DListFind(plist, x))
	{
		DListErase(cur);
	}
}

void DListPrint(DList* plist)
{
	assert(plist);

	DListNode *cur;

	printf("HEAD");
	for (cur = plist->_head->_prev; cur != plist->_head; cur = cur->_prev)
	{
		printf("<- %d ->", cur->_data);
	}
	printf("HEAD");
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printf("<- %d ->", cur->_data);
	}
	printf("HEAD\n");
}