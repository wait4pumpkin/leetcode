class Solution {
public:
	string reverseString(string s) {
		string result;
		for (auto it = s.rbegin(); it != s.rend(); ++it) {
			result.push_back(*it);
		}
		return result;
	}
};