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
	int widthOfBinaryTree(TreeNode* root) {
		if (!root) return 0;

		int result = 0;
		queue<pair<TreeNode*, int>> row;
		row.emplace(make_pair(root, 1));
		while (!row.empty()) {
			result = max(result, row.back().second - row.front().second + 1);

			queue<pair<TreeNode*, int>> next;
			while (!row.empty()) {
				auto pair = row.front();
				row.pop();

				auto node = pair.first;
				auto idx = pair.second;
				if (node->left) next.emplace(make_pair(node->left, idx * 2 - 1));
				if (node->right) next.emplace(make_pair(node->right, idx * 2));
			}
			swap(row, next);
		}
		return result;
	}
};