class NumArray {
public:
	NumArray(vector<int> nums) {
		memo.resize(nums.size() + 1);
		memo[0] = 0;

		auto sum = 0;
		auto save = memo.begin() + 1;
		for (auto load = nums.cbegin(); load != nums.cend(); ++load, ++save) {
			sum += *load;
			*save = sum;
		}
	}
	
	int sumRange(int i, int j) {
		return memo[j + 1] - memo[i];
	}

private:
	vector<int> memo;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */