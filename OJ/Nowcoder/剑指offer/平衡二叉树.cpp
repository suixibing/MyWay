class Solution {
    int _treeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return 0;
        int lhs = _treeDepth(pRoot->left);
        int rhs = _treeDepth(pRoot->right);
        return lhs > rhs ? lhs + 1 : rhs + 1;
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return true;
        if (!IsBalanced_Solution(pRoot->left) || !IsBalanced_Solution(pRoot->right))
            return false;
        int ret = _treeDepth(pRoot->right) - _treeDepth(pRoot->left);
        return ret >= -1 && ret <= 1;
    }
};