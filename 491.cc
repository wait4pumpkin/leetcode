class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<Node> memo(nums.size());
		for (auto n = 0; n < nums.size(); ++n) {
			auto &node = memo[n];
			node.value = nums[n];

			for (auto next = n + 1; next < nums.size(); ++next) {
				if (nums[next] >= nums[n]) {
					node.children.push_back(next);
				}
			}
		}

		set<vector<int>> paths;
		for (auto n = 0; n < nums.size(); ++n) {
			stack<pair<int, vector<int>>> pending;
			pending.push(make_pair(n, vector<int>()));
			while (!pending.empty()) {
				auto content = pending.top();
				pending.pop();

				auto &node = memo[content.first];
				auto &path = content.second;
				path.push_back(node.value);
				if (path.size() >= 2) paths.insert(path);

				for (auto child : node.children) {
					pending.push(make_pair(child, path));
				}
			}
		}

		vector<vector<int>> result;
		result.insert(result.end(), paths.begin(), paths.end());
		return result;
	}

private:
	struct Node {
		int value;
		vector<int> children;
	};
};