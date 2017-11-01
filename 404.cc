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
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root) return 0;

		auto result = 0;
		stack<TreeNode*> pending;
		pending.push(root);
		while (!pending.empty()) {
			auto node = pending.top();
			pending.pop();

			if (node->left) {
				if (!node->left->left && !node->left->right) result += node->left->val;
				pending.push(node->left);
			}

			if (node->right) pending.push(node->right);
		}
		return result;
	}
};