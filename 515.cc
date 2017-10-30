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
	vector<int> largestValues(TreeNode* root) {
		vector<int> result;
		if (!root) return result;

		queue<TreeNode*> row;
		row.push(root);
		while (!row.empty()) {
			auto value = INT_MIN;
			queue<TreeNode*> next;
			while (!row.empty()) {
				auto node = row.front();
				row.pop();

				value = max(value, node->val);
				if (node->left) next.push(node->left);
				if (node->right) next.push(node->right);
			}
			result.push_back(value);
			swap(row, next);
		}
		return result;
	}
};