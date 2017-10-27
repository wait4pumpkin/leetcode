class Solution {
public:
	int findMin(vector<int>& nums) {
		auto lo = 0, hi = static_cast<int>(nums.size()) - 1;
		while (hi > lo) {
			auto mid = lo + (hi - lo) / 2;
			if (nums[lo] > nums[mid] || nums[lo] < nums[hi]) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		return nums[lo];
	}
};