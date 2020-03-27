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
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        vector<int> res;
        queue<TreeNode*> que;
        TreeNode *cur = root;
        if (cur)
            que.push(cur);
        while (!que.empty())
        {
            cur = que.front();
            que.pop();
            res.push_back(cur->val);
            if (cur->left)
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
        }
        return res;
    }
};