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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        if (pRoot1->val == pRoot2->val)
        {
            return (pRoot2->left == nullptr || HasSubtree(pRoot1->left, pRoot2->left))
                && (pRoot2->right == nullptr || HasSubtree(pRoot1->right, pRoot2->right))
                || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
        else
        {
            return HasSubtree(pRoot1->left, pRoot2)
                || HasSubtree(pRoot1->right, pRoot2);
        }
    }
};