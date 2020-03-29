/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* subConvert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree || !pRootOfTree->left && !pRootOfTree->right)
            return pRootOfTree;
        TreeNode *head = subConvert(pRootOfTree->left);
        pRootOfTree->right = subConvert(pRootOfTree->right);
        if (head == nullptr)
            head = pRootOfTree;
        else
        {
            TreeNode *cur = head;
            while (cur->right)
                cur = cur->right;
            cur->right = pRootOfTree;
        }
        return head;
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr)
            return nullptr;
        TreeNode *head = subConvert(pRootOfTree), *cur = head;
        while (cur->right)
        {
            cur->right->left = cur;
            cur = cur->right;
        }
        return head;
    }
};