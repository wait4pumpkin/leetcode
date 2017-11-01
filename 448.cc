class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		for (auto n = 0; n < nums.size(); ++n) {
			while (nums[n] != n + 1 && nums[nums[n] - 1] != nums[n]) {
				swap(nums[n], nums[nums[n] - 1]);
			}
		}

		vector<int> result;
		for (auto n = 0; n < nums.size(); ++n) {
			if (nums[n] != n + 1) result.push_back(n + 1);
		}
		return result;
	}
};