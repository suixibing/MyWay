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
    vector< vector<int> > FindPath(TreeNode* root,int expectNumber)
    {
        if (root == nullptr)
            return vector< vector<int> >();
        else if (root->left == nullptr && root->right == nullptr)
        {
            if (expectNumber != root->val)
                return vector< vector<int> >();
            return vector< vector<int> >(1, vector<int>(1, root->val));
        }
        int i = 0, j = 0;
        vector< vector<int> > res, tmp;
        res = FindPath(root->left, expectNumber - root->val);
        tmp = FindPath(root->right, expectNumber - root->val);
        for (int i = 0; i < res.size(); ++i)
            res[i].insert(res[i].begin(), root->val);
        for (int i = 0; i < tmp.size(); ++i)
            tmp[i].insert(tmp[i].begin(), root->val);
        res.insert(res.end(), tmp.begin(), tmp.end());
        sort(res.begin(), res.end(), [](vector<int> &lhs, vector<int> &rhs)
        {
            return lhs.size() > rhs.size();
        });
        return res;
    }
};