/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int cnt = 0;
        TreeNode *cur = pRoot;
        stack<TreeNode*> s;
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            if (!s.empty())
            {
                ++cnt;
                cur = s.top();
                s.pop();
                if (cnt == k)
                    return cur;
                cur = cur->right;
            }
        }
        return nullptr;
    }
};