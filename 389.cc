class Solution {
public:
	char findTheDifference(string s, string t) {
		int counter[26] = { 0 };
		for (auto c : s) {
			counter[c - 'a'] += 1;
		}
		for (auto c : t) {
			counter[c - 'a'] -= 1;
		}
		for (auto n = 0; n < sizeof(counter) / sizeof(counter[0]); ++n) {
			if (counter[n] < 0) return 'a' + n;
		}
		return '\0';
	}
};