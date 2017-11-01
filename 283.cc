class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		auto iterator = nums.begin(), insert = nums.begin();
		while (iterator != nums.end()) {
			if (*iterator != 0) {
				*(insert++) = *iterator;
			}
			++iterator;
		}

		while (insert != nums.end()) {
			*(insert++) = 0;
		}
	}
};