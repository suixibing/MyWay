/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        if (pHead == nullptr)
            return pHead;
        ListNode *cur = pHead->next, *newHead = pHead, *tmp;
        newHead->next = nullptr;
        while (cur)
        {
            tmp = cur;
            cur = cur->next;
            tmp->next = newHead;
            newHead = tmp;
        }
        return newHead;
    }
};