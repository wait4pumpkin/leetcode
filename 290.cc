class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> mapping;

		string word;
		vector<string> words;
		istringstream in(str);
		while (in >> word) words.push_back(word);

		if (pattern.size() != words.size()) return false;

		unordered_map<string, bool> marks;
		for (auto n = 0; n < pattern.size(); ++n) {
			const auto iterator = mapping.find(pattern[n]);
			if (iterator == mapping.end()) {
				mapping[pattern[n]] = words[n];
				marks[words[n]] = true;
			} else if (iterator->second != words[n]) {
				return false;
			}
		}

		return marks.size() == mapping.size();
	}
};
