class Solution {
public:
	string addStrings(string num1, string num2) {
		stack<int> nums;
		auto num = 0;
		for (auto idxA = static_cast<int>(num1.size()) - 1, idxB = static_cast<int>(num2.size()) - 1; idxA >= 0 || idxB >= 0; ) {
			if (idxA >= 0 && idxB >= 0) {
				num += num1[idxA--] + num2[idxB--] - '0' - '0';
			} else if (idxA >= 0) {
				num += num1[idxA--] - '0';
			} else {
				num += num2[idxB--] - '0';
			}
			nums.push(num % 10);
			num = num / 10;
		}
		if (num > 0) nums.push(num);

		string result;
		while (!nums.empty()) {
			result.push_back(nums.top() + '0');
			nums.pop();
		}
		return result;
	}
};