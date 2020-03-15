/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        if (head == nullptr)
            return vector<int>();
        ListNode *cur = head;
        vector<int> ret;
        while (cur)
        {
            ret.push_back(cur->val);
            cur = cur->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};