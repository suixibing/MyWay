/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        map<RandomListNode*, RandomListNode*> book;
        RandomListNode *res = new RandomListNode(pHead->label);
        RandomListNode *cur = pHead, *tmp = res;
        book[cur] = tmp;
        while (cur->next)
        {
            cur = cur->next;
            tmp->next = new RandomListNode(cur->label);
            tmp = tmp->next;
            book[cur] = tmp;
        }
        for (cur = pHead, tmp = res; cur; cur = cur->next, tmp = tmp->next)
        {
            if (cur->random)
                tmp->random = book[cur->random];
        }
        return res;
    }
};