class Solution {
public:
	int majorityElement(vector<int>& nums) {
		auto count = 0;
		auto result = 0;
		for (auto n : nums) {
			if (count == 0) {
				++count;
				result = n;
			} else {
				if (result == n) {
					++count;
				} else {
					--count;
				}
			}
		}
		return result;
	}
};