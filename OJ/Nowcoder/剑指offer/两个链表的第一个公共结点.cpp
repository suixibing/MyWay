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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1 || !pHead2)
            return nullptr;
        ListNode *cur1 = pHead1, *cur2 = pHead2;
        while (cur1 && cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while (cur1)
        {
            cur1 = cur1->next;
            pHead1 = pHead1->next;
        }
        while (cur2)
        {
            cur2 = cur2->next;
            pHead2 = pHead2->next;
        }
        while (pHead1 != pHead2)
        {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};