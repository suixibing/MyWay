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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *p1 = pHead, *p2 = pHead;
        while (p1 && p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if (p2)
                p2 = p2->next;
            if (p1 && p1 == p2)
            {
                p1 = pHead;
                while (p1 != p2)
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1;
            }
        }
        return nullptr;
    }
};