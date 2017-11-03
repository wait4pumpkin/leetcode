class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> path;
		vector<vector<int>> result;
		findSubsequences(nums, 0, path, result);
		return result;
	}

private:
	void findSubsequences(vector<int> &nums, const int start, vector<int> &path, vector<vector<int>> &result) {
		if (path.size() > 1) result.push_back(path);

		unordered_set<int> visited;
		for (auto n = start; n < nums.size(); ++n) {
			if ((path.empty() || nums[n] >= path.back()) && visited.find(nums[n]) == visited.end()) {
				visited.insert(nums[n]);
				path.push_back(nums[n]);
				findSubsequences(nums, n + 1, path, result);
				path.pop_back();
			}
		}
	}
};
