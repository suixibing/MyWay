/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode *cur, *tmp;
        while (pHead && pHead->next
            && pHead->val == pHead->next->val)
        {
            int x = pHead->val;
            while (pHead && pHead->val == x)
            {
                tmp = pHead;
                pHead = pHead->next;
                delete tmp;
            }
        }
        cur = pHead;
        while (cur)
        {
            if (cur->next && cur->next->next 
               && cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x)
                {
                    tmp = cur->next;
                    cur->next = tmp->next;
                    delete tmp;
                }
            }
            else
                cur = cur->next;
        }
        return pHead;
    }
};