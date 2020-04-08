/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode *res = pNode;
        if (res == nullptr)
            return nullptr;
        if (res->right || res->next == nullptr)
        {
            res = res->right;
            while (res && res->left)
                res = res->left;
        }
        else if (res->next && res->next->left == res)
            res = res->next;
        else if (res->next && res->next->right == res)
        {
            while (res->next && res->next->right == res)
                res = res->next;
            res = res->next;
        }
        return res;
    }
};