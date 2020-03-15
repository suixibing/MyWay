/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() == 0)
            return nullptr;
        int i;
        for (i = 0; i < vin.size(); ++i)
        {
            if (vin[i] == pre[0])
                break;
        }
        TreeNode *root = new TreeNode(pre[0]);
        root->left = reConstructBinaryTree
            (vector<int>(pre.begin() + 1, pre.begin() + 1 + i), 
             vector<int>(vin.begin(), vin.begin() + i));
        root->right = reConstructBinaryTree
            (vector<int>(pre.begin() + 1 + i, pre.end()), 
             vector<int>(vin.begin() + 1 + i, vin.end()));
        return root;
    }
};