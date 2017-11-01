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
public:
	TreeNode* convertBST(TreeNode* root) {
		auto sum = 0;
		return convertBST(root, sum);
	}

private:
	TreeNode* convertBST(TreeNode *root, int &sum) {
		if (!root) return nullptr;

		auto node = new TreeNode(root->val);
		node->right = convertBST(root->right, sum);
		node->val += sum;
		sum += root->val;
		node->left = convertBST(root->left, sum);
		return node;
	}
};