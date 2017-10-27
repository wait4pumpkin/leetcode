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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root) return result;

		stack<pair<TreeNode*, string>> pending;
		pending.emplace(make_pair(root, ""));
		while (!pending.empty()) {
			auto top = pending.top();
			pending.pop();

			auto node = top.first;
			auto prefix = top.second;
			if (!node->left && !node->right) {
				result.emplace_back(prefix + to_string(node->val));
			} else {
				if (node->right) pending.emplace(make_pair(node->right, prefix + to_string(node->val) + "->"));
				if (node->left) pending.emplace(make_pair(node->left, prefix + to_string(node->val) + "->"));
			}
		}
		return result;
	}
};