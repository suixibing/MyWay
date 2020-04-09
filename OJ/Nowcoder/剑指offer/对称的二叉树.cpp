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
    TreeNode *m_tmp;
    TreeNode* makeMirror(TreeNode *pRoot)
    {
        TreeNode *tmp = nullptr;
        if (pRoot)
        {
            tmp = new TreeNode(pRoot->val);
            tmp->left = makeMirror(pRoot->right);
            tmp->right = makeMirror(pRoot->left);
        }
        return tmp;
    }
    void deleteTreeNode(TreeNode *pRoot)
    {
        if (pRoot != nullptr)
        {
            deleteTreeNode(pRoot->left);
            deleteTreeNode(pRoot->right);
            delete pRoot;
        }
    }
    void destructTree(TreeNode *pRoot)
    {
        deleteTreeNode(pRoot);
        pRoot = nullptr;
    }
    bool isEqualTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 == pRoot2)
            return true;
        else if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        return pRoot1->val == pRoot2->val 
            && isEqualTree(pRoot1->left, pRoot2->left)
            && isEqualTree(pRoot1->right, pRoot2->right);
    }
public:
    bool isSymmetrical(TreeNode *pRoot)
    {
        m_tmp = makeMirror(pRoot);
        bool flag = isEqualTree(pRoot, m_tmp);
        destructTree(m_tmp);
        return flag;
    }
};