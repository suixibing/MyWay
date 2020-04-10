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
    void reverse(vector<int> &arr)
    {
        int size = arr.size();
        for (int i = 0; i < size / 2; ++i)
            swap(arr[i], arr[arr.size() - 1 - i]);
    }
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
    vector< vector<int> > Print(TreeNode *pRoot)
    {
        vector< vector<int> > res;
        getLineData(pRoot, res, 1);
        for (int i = 1; i <= res.size(); ++i)
        {
            if (i % 2 == 0)
                reverse(res[i - 1]);
        }
        return res;
    }
    
};