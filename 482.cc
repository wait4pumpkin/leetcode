class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string result;
		auto counter = 0;
		for (auto it = S.crbegin(); it != S.crend(); ++it) {
			if (*it == '-') continue;
			result.push_back(toupper(*it));
			if ((++counter % K) == 0) result.push_back('-');
		}
		if (result.back() == '-') result.pop_back();
		reverse(result.begin(), result.end());
		return result;
	}
};