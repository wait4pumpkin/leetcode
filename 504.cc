class Solution {
public:
	string convertToBase7(int num) {
		if (!num) return "0";

		string result;
		bool minus = num < 0;
		num = abs(num);
		while (num > 0) {
			result.push_back((num % 7) + '0');
			num /= 7;
		}

		if (minus) result.push_back('-');
		reverse(result.begin(), result.end());
		return result;
	}
};