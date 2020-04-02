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
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return 0;
        int lhs = TreeDepth(pRoot->left);
        int rhs = TreeDepth(pRoot->right);
        return lhs > rhs ? lhs + 1 : rhs + 1;
    }
};