class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.size() < 2) return true;

		bool flag;
		if (isLower(word[0])) flag = true;
		else flag = isLower(word[1]);

		for (auto n = 1; n < word.size(); ++n) {
			if (isLower(word[n]) != flag) return false;
		}
		return true;
	}

private:
	bool isLower(char c) {
		return c >= 'a' && c <= 'z';
	}
};