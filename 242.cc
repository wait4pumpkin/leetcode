class Solution {
public:
	bool isAnagram(string s, string t) {
		int counter[26] = { 0 };
		for (auto it = s.cbegin(); it != s.cend(); ++it) ++counter[*it - 'a'];
		for (auto it = t.cbegin(); it != t.cend(); ++it) --counter[*it - 'a'];
		for (auto n = 0; n < sizeof(counter) / sizeof(counter[0]); ++n) if (counter[n] != 0) return false;
		return true;
	}
};