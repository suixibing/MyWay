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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return (pHead1 != nullptr) ? pHead1 : pHead2;
        ListNode *head, *cur;
        if (pHead1->val < pHead2->val)
        {
            head = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            head = pHead2;
            pHead2 = pHead2->next;
        }
        cur = head;
        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        cur->next = (pHead1 != nullptr) ? pHead1 : pHead2;
        return head;
    }
};