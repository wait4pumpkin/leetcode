class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> result;
		auto three = 0, five = 0;
		for (auto x = 1; x <= n; ++x) {
			++three;
			++five;

			if (three == 3 && five == 5) {
				result.push_back("FizzBuzz");
				three = 0;
				five = 0;
			} else if (three == 3) {
				result.push_back("Fizz");
				three = 0;
			} else if (five == 5) {
				result.push_back("Buzz");
				five = 0;
			} else {
				result.push_back(to_string(x));
			}
		}
		return result;
	}
};