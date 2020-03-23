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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if (pListHead == nullptr)
            return nullptr;
        ListNode *cur = pListHead, *other = cur->next;
        while (--k)
        {
            if (other == nullptr)
                return nullptr;
            other = other->next;
        }
        while (other)
        {
            other = other->next;
            cur = cur->next;
        }
        return cur;
    }
};