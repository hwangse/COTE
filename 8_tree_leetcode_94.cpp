/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
private:
	vector<int> ans;

	void inOrder(TreeNode *current) {
		if (!current) return;

		inOrder(current->left);
		ans.push_back(current->val);
		inOrder(current->right);
	}
public:
	vector<int> inorderTraversal(TreeNode* root) {
		inOrder(root);
		return ans;
	}

};