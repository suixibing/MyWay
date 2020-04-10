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
	string subSerialize(TreeNode *root)
	{
		if (root == nullptr)
			return "#!";
		return to_string(root->val) + "!"
			+ subSerialize(root->left)
			+ subSerialize(root->right);
	}
	TreeNode* subDeserialize(const vector<string> &data, vector<string>::size_type &pos)
	{
		TreeNode *root = nullptr;
		if (pos >= data.size() || data[pos] == "#")
			return root;
		root = new TreeNode(atoi(data[pos].c_str()));
		root->left = subDeserialize(data, ++pos);
		root->right = subDeserialize(data, ++pos);
		return root;
	}
public:
	char* Serialize(TreeNode *root)
	{
		string tmp = subSerialize(root);
		char *ret = new char[tmp.size() + 1];
		strcpy(ret, tmp.c_str());
		return ret;
	}
	TreeNode* Deserialize(char *str)
	{
		string input(str);
		vector<string> arr;
		string::size_type start = 0, pos = 0;
		while ((pos = input.find("!", pos)) != string::npos)
		{
			arr.push_back(input.substr(start, pos - start));
			start = ++pos;
		}
		pos = 0;
		return subDeserialize(arr, pos);
	}
};