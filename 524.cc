class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		auto length = s.size();
		string result;
		for (const auto& candidate : d) {
			if (candidate.size() > length) continue;

			string::const_iterator it = s.begin();
			string::const_iterator idx = candidate.begin();
			while (it != s.end() && idx != candidate.end()) {
				if (*(it++) == *idx) ++idx;
			}

			if (idx == candidate.end() && (candidate.size() > result.size() || (candidate.size() == result.size() && candidate < result))) {
				result = candidate;
			}
		}
		return result;
	}
};