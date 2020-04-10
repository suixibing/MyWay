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
    void getLineData(TreeNode *pRoot, vector< vector<int> > &res, int lineno)
    {
        if (pRoot)
        {
            if (res.size() < lineno)
                res.push_back(vector<int>(1, pRoot->val));
            else
                res[lineno - 1].push_back(pRoot->val);
            getLineData(pRoot->left, res, lineno + 1);
            getLineData(pRoot->right, res, lineno + 1);
        }
    }
public:
    vector< vector<int> > Print(TreeNode* pRoot)
    {
        vector< vector<int> > res;
        getLineData(pRoot, res, 1);
        return res;
    }
};